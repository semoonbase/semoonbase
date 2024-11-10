
all: prepare

prepare: prepare-dir prepare-godot

prepare-dir:
	python3 scripts/prepare.py

prepare-godot:
	python3 projects/asset-pipeline/main.py

tg-editor:
	build/cache/processed/Godot_v4.3-stable_mono_linux_x86_64.zip/Godot_v4.3-stable_mono_linux_x86_64/Godot_v4.3-stable_mono_linux.x86_64 -e --path projects/tank-game


clean:
	rm -rf build/