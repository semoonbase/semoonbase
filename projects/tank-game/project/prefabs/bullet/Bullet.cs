using Godot;
using System;

public partial class Bullet : AnimatableBody2D
{
	[Signal]
	public delegate void HitSomethingEventHandler(ulong CollidingObjectId);
	private float _lifetime = 1f;
	private Vector2 _velocity;
	

	public void launch(Vector2 direction, float speed){
		_velocity = direction * speed;
		GetNode<Timer>("Lifetime").Start(_lifetime);
	}
	public override void _PhysicsProcess(double delta)
	{
		var collisionInfo = MoveAndCollide(_velocity * (float)delta);
		if (collisionInfo != null)
		{
			var collisionPoint = collisionInfo.GetPosition();
			//GD.Print("I collided with ", ((Node)collisionInfo.GetCollider()).Name);
			EmitSignal(SignalName.HitSomething, collisionInfo.GetColliderId());
		}
		if (GetNode<Timer>("Lifetime").IsStopped()){
			this.QueueFree();
		}
	}
}
