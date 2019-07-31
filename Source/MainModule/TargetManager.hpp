#pragma once

#include "../MainModule/ThreadedManager.hpp"

class FTargetManager : public FThreadedManager {

protected:

	FVector _location;
	FRotator _rotation;
	
	virtual void performTask(double currentTime) override
	{
		computeState(currentTime);
	}

	FTargetManager() : FThreadedManager()
	{
		_location = FVector(0, 10, 0);
		_rotation = FVector(0, 0, 0);
	}

	virtual void computeState(double currentTime) = 0;

public:

	const FVector & getLocation(void)
	{
		return _location;
	}
	
	const FRotator & getRotation(void)
	{
		return _rotation;
	}
};
