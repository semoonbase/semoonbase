using Godot;
using System;

public partial class Main : Node2D
{
	public PackedScene crateScene;
	// Called when the node enters the scene tree for the first time.
	public override void _Ready()
	{
		crateScene = GD.Load<PackedScene>("res://prefabs/crate/Crate.tscn");
	}
	//TODO: Implement Blackboard Patterning for handling Health, Hits, and Object Positioning
	// Called every frame. 'delta' is the elapsed time since the previous frame.
	public override void _Process(double delta)
	{
	}
}
