// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

int32 AMyActor::Step() {
	return rand() % 2;
}

float AMyActor::Distance(vector<int>first, vector<int>second) {
	float dx = first[0] - second[0];
	float dy = first[1] - second[1];
	return FMath::Sqrt(dx * dx + dy * dy);
}

int32 AMyActor::createEvent() {
	return rand() % 2;
}

void AMyActor::Move(int& x, int& y) {
	vector<vector<int>> coord;
	coord.push_back({ x,y });
	for (int i = 0; i < 10; i++) {
		x += Step();
		y += Step();
		coord.push_back({ x,y });
		float dist = Distance(coord[i], coord[i + 1]);
		sum += dist;
		UE_LOG(LogTemp, Warning, TEXT("Current XY: %d, %d"), x, y);
		UE_LOG(LogTemp, Warning, TEXT("Dist: %f"), dist);
		if (!createEvent()) {
			UE_LOG(LogTemp, Warning, TEXT("Event occur"));
			event_count += 1;
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("Event not occur"));
		}
	}
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	int x = 0;
	int y = 0;
	UE_LOG(LogTemp, Warning, TEXT("Begin XY: %d, %d"), x, y);
	srand((unsigned int)time(NULL));
	Move(x,y);
	UE_LOG(LogTemp, Warning, TEXT("Dist sum: %f, Event count: %d"), sum, event_count);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


