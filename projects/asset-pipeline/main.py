#! SEMoonbase godot environment fetch script.

import os
import shutil
import zipfile
import urllib.request
import platform
import json

from task_flow import Progression, Pipeline, Task


class Ent:
    DL_SRC = 0
    DL_DEST = 1
    EXTRACT_SRC = 2
    EXTRACT_DEST = 3

def main():
    config = Configuration()
    Progression([
        Task(Statics.extracted_dl, Initial.url(config.get_tool_url("gdmono"))),
        Task(Statics.cached_dl, Initial.url(config.get_tool_url("gdmono-export-templates")))
    ]).exec_all()

class Initial:
    def url(url):
        return {
            Ent.DL_SRC: url
        }

class Flows:

    def dl_dest(world):
        """Map a godot download url to its cache path."""
        dest = Statics.download_prelude + os.path.basename(world[Ent.DL_SRC])
        world[Ent.DL_DEST] = dest

    def cached_download(world, request = urllib.request):
        src = world[Ent.DL_SRC]
        dest = world[Ent.DL_DEST]

        if not os.path.exists(dest):
            print(f"Downloading: {src}")
            request.urlretrieve(src, dest)
        else:
            print(f"Skipping: {src}")

    def extract_dest(world):
        dl_dest = world[Ent.DL_DEST]
        world[Ent.EXTRACT_SRC] = dl_dest
        world[Ent.EXTRACT_DEST] = Statics.extract_prelude + dl_dest[Statics.download_prelude_len:]

    def process_zip_extract(world, ZipFile = zipfile.ZipFile):
        """Extracts a zip archive at `EntKey.EXTRACT_SRC` to `EntKey.EXTRACT_DEST`."""

        src = world[Ent.EXTRACT_SRC]
        dest = world[Ent.EXTRACT_DEST]

        with ZipFile(src, 'r') as archive:
            archive.extractall(dest)

    def process_copy(world, copytree = shutil.copytree, copy2 = shutil.copy2):
        """Extracts a folder by copying it to the process"""

        src = world[Ent.EXTRACT_SRC]
        dest = world[Ent.EXTRACT_DEST]

        if os.path.isdir(src):
            copytree(src, dest, dirs_exist_ok=True)
        else:
            copy2(src, dest)
        
    
class Configuration:
    __tooling_defs = {}
    __plat_name = None
    __plat_arch = None

    def __init__(self):
        with open("tooling.json", 'r') as f:
            self.__tooling_defs = json.load(f)
            self.__plat_name = platform.system()
            self.__plat_arch = self.__map_arch(self.__plat_name, platform.architecture())
    
    def __map_arch(self, sys, arch):
        match arch[0]:
            case '32bit':
                return "x86"
            case '64bit':
                return "x86_64"
    
    def get_tool_url(self, name):
        # Check if tool is in platform agnostic list
        if name in self.__tooling_defs['NoPlat']:
            return self.__tooling_defs['NoPlat'][name]
        # Check if tool is in active platform specific list
        else:
            return self.__tooling_defs[self.__plat_name][self.__plat_arch][name]

class Statics:
    godot_url = "https://github.com/godotengine/godot/releases/download/4.3-stable/Godot_v4.3-stable_mono_linux_x86_64.zip"
    godot_export_templates = "https://github.com/godotengine/godot/releases/download/4.3-stable/Godot_v4.3-stable_mono_export_templates.tpz"

    download_prelude = "build/cache/download/"
    download_prelude_len = len(download_prelude)

    extract_prelude = "build/cache/processed/"

    __basic_dl = [Flows.dl_dest, Flows.cached_download]
    __cp_extract = [Flows.extract_dest, Flows.process_copy]
    __zip_extract = [Flows.extract_dest, Flows.process_zip_extract]

    cached_dl = Pipeline(__basic_dl + __cp_extract)
    extracted_dl = Pipeline(__basic_dl + __zip_extract)

if __name__ == "__main__":
    main()