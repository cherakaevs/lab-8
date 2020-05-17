#include "OrderedVector.h"
#include "UnorderedSet.h"
#include "Set.h"
#include <chrono>
#include "readInt.h"

using namespace std;

int sizes[] = { 10, 100, 1000, 10000 };

int main() {

	chrono::steady_clock time;
	chrono::duration<double> time_insert;
	chrono::duration<double> time_contains;
	chrono::duration<double> time_remove;

	double average_time_insert[4] = { 0,0,0,0 };
	double average_time_contains[4] = { 0,0,0,0 };
	double average_time_remove[4] = { 0,0,0,0 };

	

	bool key = true;
	int selectedCollection;
	int count = 0;


	while (1) {
		cout << "Choose collection:\n1.Ordered Vector\n2.Unordered Set\n3.Set\n4.Print average time\n0.Exit\n" << endl;
		selectedCollection = read_int("Enter num: ", 0, 4);

		switch (selectedCollection) {
		case 1: {
			OrderedVector<int> collection;

			for (auto j = 0; j < 4; ++j) {

				cout << "Simulation for " << sizes[j] << " elements in collection" << endl;

				for (size_t i = 0; i < sizes[j]; ++i) {
					collection.Insert(rand());
				}
				int randNum = rand();
				cout << "randNum= " << randNum << endl;

				auto start = time.now();
				collection.Insert(randNum);
				auto end = time.now();
				time_insert = end - start;
				
				start = time.now();
				collection.Contains(randNum);
				end = time.now();
				time_contains = end - start;
				

				start = time.now();
				collection.Remove(randNum);
				end = time.now();
				time_remove = end - start;
				
				

				cout << "Time insert = " << time_insert.count() << endl;
				cout << "Time Contains=  " << time_contains.count() << endl;
				cout << "Time Remove= " << time_remove.count() << endl;
				cout << endl;

				average_time_insert[j] += time_insert.count();
				average_time_contains[j] += time_contains.count();
				average_time_remove[j] += time_remove.count();

				++count;
			}
		}
				break;
		case 2: {
			UnorderedSet<int> collection;
			for (auto j = 0; j < 4; ++j) {

				cout << "Simulation for " << sizes[j] << " elements in collection" << endl;

				for (size_t i = 0; i < sizes[j]; ++i) {
					collection.Insert(rand());
				}
				int randNum = rand();
				cout << "randNum= " << randNum << endl;

				auto start = time.now();
				collection.Insert(randNum);
				auto end = time.now();
				time_insert = end - start;
				

				start = time.now();
				collection.Contains(randNum);
				end = time.now();
				time_contains = end - start;
				

				start = time.now();
				collection.Remove(randNum);
				end = time.now();
				time_remove= end - start;
				

				cout << "Time insert = " << time_insert.count() << endl;
				cout << "Time Contains=  " << time_contains.count() << endl;
				cout << "Time Remove= " << time_remove.count() << endl;
				cout << endl;

				average_time_insert[j] += time_insert.count();
				average_time_contains[j] += time_contains.count();
				average_time_remove[j] += time_remove.count();

				++count;
			}
		}
				break;
		case 3: {
			Set<int> collection;
			for (auto j = 0; j < 4; ++j) {


				cout << "Simulation for " << sizes[j] << " elements in collection" << endl;

				for (size_t i = 0; i < sizes[j]; ++i) {
					collection.Insert(rand());
				}
				int randNum = rand();
				cout << "randNum= " << randNum << endl;

				auto start = time.now();
				collection.Insert(randNum);
				auto end = time.now();
				time_insert = end - start;
				

				start = time.now();
				collection.Find(randNum);
				end = time.now();
				time_contains = end - start;
				

				start = time.now();
				collection.Remove(randNum);
				end = time.now();
				time_remove = end - start;

				cout << "Time insert = " << time_insert.count() << endl;
				cout << "Time Contains=  " << time_contains.count() << endl;
				cout << "Time Remove= " << time_remove.count() << endl;
				cout << endl;

				average_time_insert[j] += time_insert.count();
				average_time_contains[j] += time_contains.count();
				average_time_remove[j] += time_remove.count();

				++count;
			} break;
		}

		case 0:
			return 0;
		case 4:
			for (auto j = 0; j < 4; ++j) {

				auto res1 = average_time_insert[j] / count;
				auto res2 = average_time_contains[j] / count;
				auto res3 = average_time_remove[j] / count;

				cout << "Average time insert: " << res1 << endl;
				cout << "Average time contains: " << res2 << endl;
				cout << "Average time remove: " << res3 << endl;
				cout << endl;
			}
		}
	}
}