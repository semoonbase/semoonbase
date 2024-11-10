#! /usr/bin/env python3

import sys
import shutil
import os

def main():
    argv = sys.argv
    
    if len(argv) == 1:
        prepare()
        tg_editor()
        pass
    else:
        match argv[1]:
            case "clean":
                clean()
            case "prepare":
                prepare()
            case "prepare-dir":
                prepare_dir()
            case "prepare-godot":
                prepare_godot()
            case "tg_editor":
                tg_editor()
                

def clean():
    shutil.rmtree("build/")

def prepare():
    prepare_dir()
    prepare_godot()
    pass

def prepare_dir():
    os.system("python scripts/prepare.py")
    pass

def prepare_godot():
    os.system("python projects/asset-pipeline/main.py")
    pass

def tg_editor():
    os.system("build/cache/processed/Godot_v4.3-stable_mono_linux_x86_64.zip/Godot_v4.3-stable_mono_linux_x86_64/Godot_v4.3-stable_mono_linux.x86_64 -e --path projects/tank-game")
    pass

if __name__ == '__main__':
    main()