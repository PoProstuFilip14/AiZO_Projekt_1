#pragma once
#include <climits>

class Bucket
{
	private:
		int min;
		int max;
		int size;
		int* bucketArray;
	public:
		Bucket(int min = INT_MAX, int max = INT_MIN, int size = 0, int* bucketArray = nullptr);
		void setBucket(int min, int max, int size, int* bucketArray);
		int getMin();
		int getMax();
		int getSize();
		int* getBucketArray();
};

