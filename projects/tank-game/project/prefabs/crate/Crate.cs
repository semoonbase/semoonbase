using Godot;
using System;

public partial class Crate : RigidBody2D
{
	private ulong _colliderId;
	private ulong _myColliderId;
	public PackedScene explosionScene;
	// Called when the node enters the scene tree for the first time.
	public override void _Ready()
	{
		_myColliderId = this.GetInstanceId();
		explosionScene = GD.Load<PackedScene>("res://Explosion.tscn");
	}
	
	// Called every frame. 'delta' is the elapsed time since the previous frame.
	public override void _Process(double delta)
	{
		
	}
	private void OnTankHitSomething(ulong ColliderId)
	{
		_colliderId = ColliderId;
		if (_colliderId == _myColliderId){
			Explosion newExplosion = (Explosion)explosionScene.Instantiate();
			GetParent().AddChild(newExplosion);
			this.QueueFree();
		}
	}
}
