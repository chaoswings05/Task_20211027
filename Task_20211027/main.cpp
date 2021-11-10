#include <stdio.h>

/*
�y���z
Object�N���X
x, y, z���W��ۑ�����ϐ��AUpdate�֐������B
Update�֐���virtual�ō���Ă��������B

Vehicle(��蕨)�N���X
Object�N���X���p�������N���X�B
�����ł�setSpeed�֐���ǉ����Ă��������B
�܂�speed��accel�̕ϐ��������Œǉ����Ă��������B
setSpeed�֐���virtual�ō���Ă��������B
(���m�ȑ��x�̏������s�������ꍇ�́A�����Ɖ����x�ŁA
�x�N�g�����v�Z������@�ł��\���܂���B)

Car(��)�N���X
Vehicle�N���X���p�������N���X
Speed�̕ύX��������Car�p�Ɏ������Ă��������B

����𗝉�����Ƃ����Ӗ��ŁA���̐e�N���X����h���N���X������Ă����Ăق����̂ŁA
���̌v�Z������f�[�^�̐ݒ�̎d���́A�K���ɍs���Ă�����Č��\�ł��B

���Ԃ�����΁A
Vehicle�N���X���p�����āA
bicycle(���]��)��bike(�I�[�g�o�C)
�Ƃ������N���X�̍쐬��A
Car������Ɍp������police car��Atruck�Ȃǂ�
�N���X���쐬���Ă݂Ă��������B
*/

class Object
{
public:
	Object() {}

	~Object() {}

	virtual void Update(int newX, int newY, int newZ)
	{
		x = newX;
		y = newY;
		z = newZ;
		printf("x=%d y=%d z=%d\n", x, y, z);
	}
	int x = 0;
	int y = 0;
	int z = 0;
};

class Vehicle : public Object
{
public:
	Vehicle() {}

	~Vehicle() {}

	virtual void SetSpeed(int startSpeed)
	{
		speed = startSpeed;
		speed += accel;
		printf("speed:%d\n", speed);
	}

	virtual void Update()
	{
		SetSpeed(20);
		x += speed;
		Object::Update(x, y, z);
	}
	int speed = 0;
	int accel = 1;
};

class Car : public Vehicle
{
public:
	Car() {}

	~Car() {}

	void SetSpeed(int startSpeed)
	{
		speed = startSpeed;
		speed += accel * 10;
		printf("speed:%d\n", speed);
	}
};

class Bike : public Vehicle
{
public:
	Bike() {}

	~Bike() {}

	void Update()
	{
		SetSpeed(50);
		x += speed;
		fuel -= speed;
		Object::Update(x, y, z);
		printf("fuel=%d\n", fuel);
	}
private:
	int fuel = 1000;
};

class Truck : public Car
{
public:
	Truck() {}

	~Truck() {}

	void Update()
	{
		SetSpeed(30);
		x += speed - heavy;
		Object::Update(x, y, z);
	}
private:
	int heavy = 5;
};

int main()
{
	Object object;
	Vehicle vehicle;
	Car car;
	Bike bike;
	Truck truck;

	object.Update(5,5,5);

	vehicle.Update();

	car.Update();

	bike.Update();

	truck.Update();
}