# SEMOONBASE build directory preparation script.

import os

os.makedirs("build/cache/download", exist_ok=True)
os.makedirs("build/cache/processed", exist_ok=True)
os.makedirs("build/deps/bin", exist_ok=True)
