#include <stdio.h>
#include "MPU9250.h"

int main(){
	MPU9250 mog_mpu;
	printf("hello\n");
	mog_mpu.initialize();
	mog_mpu.testConnection();
}
