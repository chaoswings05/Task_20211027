#include <stdio.h>

/*
【問題】
Objectクラス
x, y, z座標を保存する変数、Update関数を持つ。
Update関数はvirtualで作ってください。

Vehicle(乗り物)クラス
Objectクラスを継承したクラス。
ここではSpeedUpクラスを追加してください。
またspeedとaccelの変数をここで追加してください。
SpeedUpクラスはvirtualで作ってください。
(正確な速度の処理を行いたい場合は、向きと加速度で、
ベクトルを計算する方法でも構いません。)

Car(車)クラス
Vehicleクラスを継承したクラス
Speedの変更をここでCar用に実装してください。

流れを理解するという意味で、この親クラスから派生クラスを作っていってほしいので、
中の計算処理やデータの設定の仕方は、適当に行ってもらって結構です。

時間があれば、
Vehicleクラスを継承して、
bicycle(自転車)やbike(オートバイ)
といったクラスの作成や、
Carをさらに継承したpolice carや、truckなどの
クラスを作成してみてください。
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

	virtual void SpeedUp()
	{
		speed += accel;
		printf("speed:%d\n", speed);
	}

	virtual void Update()
	{
		x += speed;
		printf("x=%d y=%d z=%d\n", x, y, z);
	}
	int speed = 0;
	int accel = 1;
};

class Car : public Vehicle
{
public:
	Car() {}

	~Car() {}

	void SpeedUp()
	{
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
		x += speed;
		fuel -= speed;
		printf("x=%d y=%d z=%d\n", x, y, z);
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
		x += speed - heavy;
		printf("x=%d y=%d z=%d\n", x, y, z);
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

	vehicle.SpeedUp();
	vehicle.Update();

	car.SpeedUp();
	car.Update();

	bike.SpeedUp();
	bike.Update();

	truck.SpeedUp();
	truck.Update();
}