//
// Created by PC_volt on 04/10/2023.
//

#ifndef SOKULIB_SOKUROLLADDRESSES_HPP
#define SOKULIB_SOKUROLLADDRESSES_HPP

// Always size 6
enum class HeapFreeHooks
{
	ADDR_HEAPFREE_1 = 0x821730,
	ADDR_HEAPFREE_2 = 0x821759,
	ADDR_HEAPFREE_3 = 0x82251E,
	ADDR_HEAPFREE_4 = 0x82F09E,
	ADDR_HEAPFREE_5 = 0x82F18C
};

// Always size 6
enum class HeapAllocHooks
{
	ADDR_HEAPALLOC_1 = 0x821704,
	ADDR_HEAPALLOC_2 = 0x8230E6,
	ADDR_HEAPALLOC_3 = 0x823397,
	ADDR_HEAPALLOC_4 = 0x82ED84,
	ADDR_HEAPALLOC_5 = 0x82F15B,
};

// Always size 6
enum class HeapReAllocHooks
{
	ADDR_HEAPREALLOC_1 = 0x82346F,
	ADDR_HEAPREALLOC_2 = 0x8233EE,
	ADDR_HEAPREALLOC_3 = 0x82F125
};

// Addresses taken from Sokuroll 1.3
// WaitForSingleObject and ReleaseMutexHooks?
/*
enum OtherHooks
{
	placeTrampoline(&LAB_100054f0,6,0x407f48);

	placeTrampoline(&LAB_1000ff00,7,0x4543f0);
	placeTrampoline(&LAB_1000ff00,6,0x4554ac);
	placeTrampoline(&LAB_1000ff00,6,0x45570b);
	placeTrampoline(&LAB_1000ff00,6,0x4557a5);
	placeTrampoline(&LAB_1000ff00,6,0x455816);
	placeTrampoline(&LAB_1000ff00,6,0x45584c);
	placeTrampoline(&LAB_1000ff00,6,0x4559a6);
	placeTrampoline(&LAB_1000ff00,6,0x455a74);
	placeTrampoline(&LAB_1000ff00,6,0x455f09);

	placeTrampoline(&LAB_1000ff10,7,0x41704a);

	placeTrampoline(&LAB_1000ff00,6,0x453616);
	placeTrampoline(&LAB_1000ff00,6,0x453731);
	placeTrampoline(&LAB_1000ff00,7,0x454614);
	placeTrampoline(&LAB_1000ff00,6,0x4546ed);
	placeTrampoline(&LAB_1000ff00,6,0x45487b);
	placeTrampoline(&LAB_1000ff00,6,0x454915);
	placeTrampoline(&LAB_1000ff00,6,0x454959);
	placeTrampoline(&LAB_1000ff00,6,0x454cf7);
	placeTrampoline(&LAB_1000ff00,6,0x45511c);

	placeTrampoline(&LAB_1000ff10,9,0x416ce4);

	placeTrampoline(&LAB_1000ff80,7,0x4543a0);
};

 RecvFrom Hook
 placeTrampoline(&LAB_1000eb60,5,0x41daea);

 Gameloop Hook
 placeTrampoline(&LAB_100054e0,9,0x407e30);
*/

#endif //SOKULIB_SOKUROLLADDRESSES_HPP
