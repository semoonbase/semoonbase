"""
Python script for building mesh models from a step file

Uses the `FreeCAD` python API to build a mesh model from a step file.
"""

import sys
import os

messages = {
    "usage": "Usage: python build_cad.py <output_file>",
}


def main():
    if len(sys.argv) < 3:
        print(messages["usage"])
        return

    input_file = "case.step"
    output_file = sys.argv[1]

    init_build_dir(output_file)


def init_build_dir(output_file):
    """Initialize the build directory to a known state

    Args:
        output_file (str): Desired path of the output file.

    Returns:
        IOError: If the output file is invalid.
        None: If the output file is valid.
    """
    out_valid = validate_outfile(output_file)
    if out_valid is None:
        maybe_makedir(output_file)
    elif out_valid is IOError:
        print(f"Invalid output file: {output_file}")
        print(messages["usage"])
        return out_valid


def maybe_makedir(path):
    """Creates a directory for a file.

    Does nothing if `path` is a directory.

    Args:
        path (str): Path to a file to maybe create parents for.
    """
    # TODO(Lucas): Validate the path should be made
    # TODO(Lucas): Propagate IO errors
    os.makedirs(os.path.dirname(path), exist_ok=True)


def validate_outfile(path):
    """Vaidate the user specified output file.

    Args:
        path (str): Path to the output file.

    Returns:
        None: If the outfile is valid.
        IOError: If the outfile is invalid.
    """
    # TODO(Lucas): Validate the path is a file
    # TODO(Lucas): Validate the file is writable
    # TODO(Lucas): Allow consuder to branch if file exists
    if isinstance(path, str):
        return
    elif os.path.isdir(path):
        return IOError(f"Output file is a directory: {path}")


if __name__ == "__main__":
    main()
