using Godot;
using System;

public partial class CharacterBody2d : CharacterBody2D
{
	public const float Speed = 50f;
	public const float Friction = 0.9f;
	public const float RotationSpeed = 2f;
	public const float BulletSpeed = 400.0f;
	private const float _epsilon = Single.Epsilon;
	private float _rotationDirection;
	private Vector2 _turretRotation;
	private Vector2 _target;
	private ulong _collisionId;
	public PackedScene bulletScene;

	private Vector2 WishDir;
	private Sprite2D Turret;
	private Sprite2D Tank;

	[Signal]
	public delegate void TankHitSomethingEventHandler(ulong CollidingObjectId);

	public override void _Ready()
	{
		bulletScene = GD.Load<PackedScene>("res://prefabs/bullet/Bullet.tscn");
		this.Turret = GetNode<Sprite2D>("Turret");
		this.Tank = GetNode<Sprite2D>("Tank");
	}
	public override void _Input(InputEvent @event)
	{
		this.WishDir.X = Input.GetAxis("left", "right");
		this.WishDir.Y = Input.GetAxis("up", "down");
		
		this.WishDir = this.WishDir.Normalized();

		_target = GetGlobalMousePosition();

		if (@event.IsActionPressed("click"))
		{
			LaunchBullet();
		}
	}
	public void LaunchBullet()
	{
		Bullet newBullet = (Bullet)bulletScene.Instantiate();
		newBullet.Position = this.Turret.GlobalPosition;
		newBullet.Rotation = this.Turret.Rotation;
		newBullet.HitSomething += OnBulletHitSomething;
		GetParent().AddChild(newBullet);
		newBullet.launch(_turretRotation, BulletSpeed);
	}

	public override void _PhysicsProcess(double delta)
	{
		// Update velocity
		this.Velocity += Speed*this.WishDir;
		if (this.Velocity.Length() > _epsilon)
		{
			this.Velocity = Friction*this.Velocity;
			// Update rotation
			// TODO: Easing function
			Rotation = _rotationDirection * RotationSpeed * (float)delta;
			if (this.WishDir.Length() != 0)
			{
				this.Tank.LookAt(this.Velocity*1000); 
			}
		}
	
		this.Turret.LookAt(_target);
		_turretRotation = Position.DirectionTo(_target);
		MoveAndSlide();
	}

	private void OnBulletHitSomething(ulong ColliderId)
	{
		_collisionId = ColliderId;
		EmitSignal(SignalName.TankHitSomething, _collisionId);
	}
}
