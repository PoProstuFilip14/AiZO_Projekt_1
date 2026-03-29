#include <climits>
#include "Bucket.h"

Bucket::Bucket(int min, int max, int size, int* bucketArray) {
	this->min = min;
	this->max = max;
	this->size = size;
	this->bucketArray = bucketArray;
}

void Bucket::setBucket(int min, int max, int size, int* bucketArray) {
	this->min = min;
	this->max = max;
	this->size = size;
	this->bucketArray = bucketArray;
}

int Bucket::getMin() {
	return min;
}

int Bucket::getMax() {
	return max;
}

int Bucket::getSize() {
	return size;
}

int* Bucket::getBucketArray() {
	return bucketArray;
}