using Godot;
using System;

public partial class Explosion : CpuParticles2D
{
	private float _lifetime = 1f;
	// Called when the node enters the scene tree for the first time.
	public override void _Ready()
	{
		GetNode<Timer>("Lifetime").Start(_lifetime);
	}

	// Called every frame. 'delta' is the elapsed time since the previous frame.
	public override void _Process(double delta)
	{
		if (GetNode<Timer>("Lifetime").IsStopped()){
			GD.Print("timer is stopped");
			this.QueueFree();
		}
	}
}
