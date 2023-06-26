#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<fstream>
#include<string>
#include<sstream>
#include "pch.h"
#include "CppUnitTest.h"
#include "shipping_r.h"
#include "UI_r.h"
#include"mapping_r.h"
#include<iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(validatePackageInput_UI_module)
	{
	public:
		//T1F8: Accept valid shipping inputs for weight, box size, and destination
		// 0 = invalid, 1 = valid, 2 = exit condition
		TEST_METHOD(T1)
		{
			int weight = 200;
			double size = 0.25;
			char* dest = "10D";
			int x = validatePackageInfo(&weight, &size, dest);
			Assert::AreEqual(1, x);
		}

		//T2F8: Reject invalid input for weight. 
		// 0 = invalid, 1 = valid, 2 = exit condition
		TEST_METHOD(T2)
		{
			int weight = 1200;
			double size = 0.25;
			char* dest = "10D";
			int x = validatePackageInfo(&weight, &size, dest);
			Assert::AreEqual(0, x);
		}


		//T3F8: Reject invalid input for weight as 0.
		// 0 = invalid, 1 = valid, 2 = exit condition
		TEST_METHOD(T3)
		{
			int weight = 0;
			double size = 0.25;
			char* dest = "10D";
			int x = validatePackageInfo(&weight, &size, dest);
			Assert::AreEqual(0, x);
		}

		//T4F8: Reject invalid input for weight using negative number.
		// 0 = invalid, 1 = valid, 2 = exit condition
		TEST_METHOD(T4)
		{
			int weight = -100;
			double size = 0.25;
			char* dest = "10D";
			int x = validatePackageInfo(&weight, &size, dest);
			Assert::AreEqual(0, x);
		}

		//T5F8: Reject invalid input for size.
		// 0 = invalid, 1 = valid, 2 = exit condition
		TEST_METHOD(T5)
		{
			int weight = 200;
			double size = 0.75;
			char* dest = "10D";
			int x = validatePackageInfo(&weight, &size, dest);
			Assert::AreEqual(0, x);
		}

		//T6F8: Reject invalid input for size as 0.
		// 0 = invalid, 1 = valid, 2 = exit condition
		TEST_METHOD(T6)
		{
			int weight = 200;
			double size = 0;
			char* dest = "10D";
			int x = validatePackageInfo(&weight, &size, dest);
			Assert::AreEqual(0, x);
		}
		//T7F8: Reject invalid input for size using negative number
		// 0 = invalid, 1 = valid, 2 = exit condition
		TEST_METHOD(T7)
		{
			int weight = 200;
			double size = -0.25;
			char* dest = "10D";
			int x = validatePackageInfo(&weight, &size, dest);
			Assert::AreEqual(0, x);
		}
		//T8F8: Reject invalid input for desination.
		// 0 = invalid, 1 = valid, 2 = exit condition
		TEST_METHOD(T8)
		{
			int weight = 200;
			double size = 0.25;
			char* dest = "30B";
			int x = validatePackageInfo(&weight, &size, dest);
			Assert::AreEqual(0, x);
		}

		//T9F8: Reject invalid input for desination as 0.
		// 0 = invalid, 1 = valid, 2 = exit condition
		TEST_METHOD(T9)
		{
			int weight = 200;
			double size = 0.25;
			char* dest = "00";
			int x = validatePackageInfo(&weight, &size, dest);
			Assert::AreEqual(0, x);
		}
		//T10F8: Reject invalid input when weight is null.
		// 0 = invalid, 1 = valid, 2 = exit condition
		TEST_METHOD(T10)
		{
			int weight = NULL;
			double size = 0.25;
			char* dest = "30B";
			int x = validatePackageInfo(&weight, &size, dest);
			Assert::AreEqual(0, x);
		}
		//T11F8: Reject invalid input when size is null.
		// 0 = invalid, 1 = valid, 2 = exit condition
		TEST_METHOD(T11)
		{
			int weight = 200;
			double size = NULL;
			char* dest = "30B";
			int x = validatePackageInfo(&weight, &size, dest);
			Assert::AreEqual(0, x);
		}
		//T12F8: Reject invalid input when destination is null.
		// 0 = invalid, 1 = valid, 2 = exit condition
		TEST_METHOD(T12)
		{
			int weight = 200;
			double size = 0.25;
			char* dest = nullptr;
			int x = validatePackageInfo(&weight, &size, dest);
			Assert::AreEqual(0, x);
		}
		//T13F8: Reject invalid input when destination is not a letter followed by a number.
		// 0 = invalid, 1 = valid, 2 = exit condition
		TEST_METHOD(T13)
		{
			int weight = 200;
			double size = 0.25;
			char* dest = "ZZ";
			int x = validatePackageInfo(&weight, &size, dest);
			Assert::AreEqual(0, x);
		}
		//T14F8: Recognize the exit condition values.
		// 0 = invalid, 1 = valid, 2 = exit condition
		TEST_METHOD(T14)
		{
			int weight = 0;
			double size = 0;
			char* dest = "x";
			int x = validatePackageInfo(&weight, &size, dest);
			Assert::AreEqual(2, x);
		}

	};
    TEST_CLASS(convertToPoint_SHIPPING_module) {
        
        /*
         
         Valid Input:-
         
         String:-
         1. Row:- 1 to 25
         2. Column:- A to Y
         
         */
        
    public:
        //T1F9: Should convert string to a variable of struct Point by dividing string into int and char type varibles.
        // 0 = Different, 1 = Same
        
        TEST_METHOD(T1F9)
        {
            struct Point expectedPoint = { 11,1 };
            char* pointString = "12B";
            struct Point actualPoint = convertToPoint(pointString);
            Assert::AreEqual(expectedPoint.row, actualPoint.row);
            Assert::AreEqual(expectedPoint.col, actualPoint.col);
        }
        
        
        
        //T2F9: passing an empty string inside the function
        // 0 = Different, 1 = Same
        
        TEST_METHOD(T2F9)
        {
            struct Point expectedPoint = { -1, -1 };
            char* pointString = "";
            struct Point actualPoint = convertToPoint(pointString);
            Assert::AreEqual(expectedPoint.row, actualPoint.row);
            Assert::AreEqual(expectedPoint.col, actualPoint.col);
        }
        
        //T3F9: Should convert exit string to a variable of struct Point by dividing string into int and char type varibles.
        // 0 = Different, 1 = Same
        
        TEST_METHOD(T3F9)
        {
            struct Point expectedPoint = { -1, -1 };
            char* pointString = "x";
            struct Point actualPoint = convertToPoint(pointString);
            Assert::AreEqual(expectedPoint.row, actualPoint.row);
            Assert::AreEqual(expectedPoint.col, actualPoint.col);
        }
        
        
        //T4F9: Should convert string containing negative int as a variable of struct Point by dividing string into int and char type varibles.
        // 0 = Different, 1 = Same
        
        TEST_METHOD(T4F9)
        {
            struct Point expectedPoint = { -1,-1 };
            char* pointString = "-15F";
            struct Point actualPoint = convertToPoint(pointString);
            Assert::AreEqual(expectedPoint.row, actualPoint.row);
            Assert::AreEqual(expectedPoint.col, actualPoint.col);
        }
        
        
        //T5F9: Should convert string with missing char to a variable of struct Point by assigning digit to int type and null to char type varible.
        // 0 = Different, 1 = Same
        
        TEST_METHOD(T5F9)
        {
            struct Point expectedPoint = { -1,-1 };
            char* pointString = "20";
            struct Point actualPoint = convertToPoint(pointString);
            Assert::AreEqual(expectedPoint.row, actualPoint.row);
            Assert::AreEqual(expectedPoint.col, actualPoint.col);
        }
        
        
        
        //T6F9: Should convert string with missing int to a variable of struct Point by assigning null to int type and user input to char type varible.
        // 0 = Different, 1 = Same
        
        TEST_METHOD(T6F9)
        {
            struct Point expectedPoint = { -1, -1 };
            char* pointString = "A";
            struct Point actualPoint = convertToPoint(pointString);
            Assert::AreEqual(expectedPoint.row, actualPoint.row);
            Assert::AreEqual(expectedPoint.col, actualPoint.col);
        }
        
    };
    TEST_CLASS(validateDestination_UI_module) {
        /*
         Destination:
         Row    : 1 to 24
         Column : A to Y
         */
    public:
        //T1F11: Valid string containing row number and column for the destination is read and should be accepted.
        // 0 = Invalid input, 1 = Valid input
        
        TEST_METHOD(T1F11)
        {
            int inputValidity;
            char* desiredDest = "12B";
            inputValidity = validateDestination(desiredDest);
            Assert::AreEqual(1, inputValidity);
        }
        
        //T2F11: Invalid string containing only column number for the destination is read and should be rejected.
        // 0 = Invalid input, 1 = Valid input
        
        TEST_METHOD(T2F11)
        {
            int inputValidity;
            char* desiredDest = "ABC";
            inputValidity = validateDestination(desiredDest);
            Assert::AreEqual(0, inputValidity);
        }
        
        //T3F11: Invalid string containing only row number for the destination is read and should be rejected.
        // 0 = Invalid input, 1 = Valid input
        
        TEST_METHOD(T3F11)
        {
            int inputValidity;
            char* desiredDest = "20";
            inputValidity = validateDestination(desiredDest);
            Assert::AreEqual(0, inputValidity);
        }
        
        //T4F11: Invalid string containing  row number which is greater than the maximum limit for the destination is read and should be rejected.
        // 0 = Invalid input, 1 = Valid input
        
        TEST_METHOD(T4F11)
        {
            int inputValidity;
            char* desiredDest = "27B";
            inputValidity = validateDestination(desiredDest);
            Assert::AreEqual(0, inputValidity);
        }
        
        
        //T5F11: Invalid string containing column number which is greater than the maximum limit for the destination is read and should be rejected.
        // 0 = Invalid input, 1 = Valid input
        
        TEST_METHOD(T5F11)
        {
            int inputValidity;
            char* desiredDest = "5Z";
            inputValidity = validateDestination(desiredDest);
            Assert::AreEqual(0, inputValidity);
        }
        
        
        //T6F11: Invalid string containing negative row number which is less than the minimum limit for the destination is read and should be rejected.
        // 0 = Invalid input, 1 = Valid input
        
        TEST_METHOD(T6F11)
        {
            int inputValidity;
            char* desiredDest = "-12B";
            inputValidity = validateDestination(desiredDest);
            Assert::AreEqual(0, inputValidity);
        }
        
        //T7F11: Invalid string containing column number which is greater than the maximum limit for the destination is read and should be rejected.
        // 0 = Invalid input, 1 = Valid input
        
        TEST_METHOD(T7F11)
        {
            int inputValidity;
            char* desiredDest = "5AB";
            inputValidity = validateDestination(desiredDest);
            Assert::AreEqual(0, inputValidity);
        }
        
        
        //T8F11: Invalid string containing no information for the destination is read and should be rejected.
        // 0 = Invalid input, 1 = Valid input
        
        TEST_METHOD(T8F11)
        {
            int inputValidity;
            char* desiredDest = "";
            inputValidity = validateDestination(desiredDest);
            Assert::AreEqual(0, inputValidity);
        }
        
        
        //T9F11: Long invalid string that also exceeds the maximum number of rows is passed through the function and should reject the input.
        // 0 = Invalid input, 1 = Valid input
        
        TEST_METHOD(T9F11)
        {
            int inputValidity;
            char* desiredDest = "50SENECA";
            inputValidity = validateDestination(desiredDest);
            Assert::AreEqual(0, inputValidity);
        }
        
    };



	TEST_CLASS(shortestDiversion_SHIPPING_module)
	{
	public:
		// T1F1: Accurately calculate the shortest diversion for map without obstructions.
		TEST_METHOD(T1F1)
		{
			struct Map map = { {{0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 0}, {1, 0, 0, 0}}, 4, 4 };
			struct Route route = { {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {2, 2}, {2, 3}}, 6, 'B', '1', 0 };
			struct Point dest = { 3, 0 };
			struct Route expectedRoute = { {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {2, 2}, {3, 1}, {3, 0}}, 7, 'B', '1', 1 };

			struct Route actualRoute = shortestDiversion(&map, &route, dest);

			Assert::AreEqual(expectedRoute.diversionLen, actualRoute.diversionLen);
			Assert::AreEqual(expectedRoute.numPoints, actualRoute.numPoints);

		}
		//T2F1: Accurately calculate the shortest diversion for map with obstructions.
		TEST_METHOD(T2F1)
		{
			struct Map map = { {{0, 0, 0, 1}, {0, 0, 0, 1}, {0, 1, 0, 0}, {1, 1, 0, 0}}, 4, 4 };
			struct Route route = { {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {2, 2}, {2, 3}}, 6, 'B', '1', 0 };
			struct Point dest = { 3, 0 };
			struct Route expectedRoute = { {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {1, 1}, {2, 0}, {3, 0}}, 7, 'B', '1', 2 };

			struct Route actualRoute = shortestDiversion(&map, &route, dest);

			Assert::AreEqual(expectedRoute.diversionLen, actualRoute.diversionLen);
			Assert::AreEqual(expectedRoute.numPoints, actualRoute.numPoints);
		}
		//T3F1: Accurately calculate the shortest diversion for a destination on route.
		TEST_METHOD(T3F1)
		{
			struct Map map = { {{0, 0, 0, 1}, {0, 0, 0, 1}, {0, 1, 0, 0}, {1, 1, 0, 0}}, 4, 4 };
			struct Route route = { {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {2, 2}, {2, 3}}, 6, 'B', '1', 0 };
			struct Point dest = { 2, 1 };
			struct Route expectedRoute = { {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {2, 2}, {2, 1}}, 5, 'B', '1', 0 };
			struct Route actualRoute = shortestDiversion(&map, &route, dest);
			Assert::AreEqual(expectedRoute.diversionLen, actualRoute.diversionLen);
			Assert::AreEqual(expectedRoute.numPoints, actualRoute.numPoints);

		}
    };
    
	TEST_CLASS(compareRoutes_SHIPPING_module) {
    public:
	// T1F2: Compare two routes based on diversion length where second route is longer than first route.
	// Returns 1 if first route has higher priority than second, and 0 otherwise.
	TEST_METHOD(T1F2)
	{
		struct Route rt1 = { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {0,5} }, 6, 'B', '1', 3 };
		struct Route rt2 = { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'Y', '2', 5 };
		struct Truck trucks[] = {
			{ '1', 50, 1.0, 0 },
			{ '2', 50, 1.0, 0 }
		};

		int x = compareRoutes(&rt1, &rt2, trucks);

		Assert::AreEqual(1, x);
	}
	// T2F2: Compare two routes based on diversion length where first route is longer than second route.
	// Returns 1 if first route has higher priority than second, and 0 otherwise.
	TEST_METHOD(T2F2)
	{
		struct Route rt1 = { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {0,5} }, 6, 'B', '1', 5 };
		struct Route rt2 = { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'Y', '2', 3 };
		struct Truck trucks[] = {
			{ '1', 50, 1.0, 0 },
			{ '2', 50, 1.0, 0 }
		};

		int x = compareRoutes(&rt1, &rt2, trucks);

		Assert::AreEqual(0, x);
	}
	// T3F2: Compare two routes based on diversion length where first route is shorter than second route, and first route is fuller than second route.
	// Returns 1 if first route has higher priority than second, and 0 otherwise.
	TEST_METHOD(T3F2)
	{
		struct Route rt1 = { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {0,5} }, 6, 'B', '1', 3 };
		struct Route rt2 = { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'Y', '2', 5 };
		struct Truck trucks[] = {
			{ '1', 700, 1.0, 0 },
			{ '2', 300, 1.0, 0 }
			// MAX_WEIGHT 1000
			// MAX_SPACE 36.0
		};

		int x = compareRoutes(&rt1, &rt2, trucks);

		Assert::AreEqual(1, x);
	}
	// T4F2: Compare two routes based on diversion length where first route is shorter than second route, and second route is fuller than first route.
	// Returns 1 if first route has higher priority than second, and 0 otherwise.
	TEST_METHOD(T4F2)
	{
		struct Route rt1 = { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {0,5} }, 6, 'B', '1', 3 };
		struct Route rt2 = { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'Y', '2', 5 };
		struct Truck trucks[] = {
			{ '1', 300, 1.0, 0 },
			{ '2', 700, 1.0, 0 }
			// MAX_WEIGHT 1000
			// MAX_SPACE 36.0
		};

		int x = compareRoutes(&rt1, &rt2, trucks);

		Assert::AreEqual(1, x);
	}
	// T5F2: Compare two routes when diversion length is equal, and first route fullness is less than second route fullness.
	// Returns 1 if first route has higher priority than second, and 0 otherwise.
	TEST_METHOD(T5F2)
	{
		struct Route rt1 = { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {0,5} }, 6, 'B', '1', 5 };
		struct Route rt2 = { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'Y', '2', 5 };
		struct Truck trucks[] = {
			{ '1', 300, 1.0, 0 },
			{ '2', 800, 1.0, 0 }
			// MAX_WEIGHT 1000
			// MAX_SPACE 36.0
		};

		int x = compareRoutes(&rt1, &rt2, trucks);

		Assert::AreEqual(1, x);
	}
	// T6F2: Compare two routes when diversion length is equal, and second route fullness is less than first route fullness.
	// Returns 1 if first route has higher priority than second, and 0 otherwise.
	TEST_METHOD(T6F2)
	{
		struct Route rt1 = { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {0,5} }, 6, 'B', '1', 5 };
		struct Route rt2 = { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'Y', '2', 5 };
		struct Truck trucks[] = {
			{ '1', 700, 1.0, 0 },
			{ '2', 100, 1.0, 0 }
			// MAX_WEIGHT 1000
			// MAX_SPACE 36.0
		};

		int x = compareRoutes(&rt1, &rt2, trucks);

		Assert::AreEqual(0, x);
	}
	// T7F2: Compare two routes when diversion length is equal, and fullness is equal but greater than 0.
	// Returns 1 if first route has higher priority than second, and 0 otherwise.
	TEST_METHOD(T7F2)
	{
		struct Route rt1 = { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {0,5} }, 6, 'B', '1', 5 };
		struct Route rt2 = { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'Y', '2', 5 };
		struct Truck trucks[] = {
			{ '1', 300, 1.0, 0 },
			{ '2', 300, 1.0, 0 }
			// MAX_WEIGHT 1000
			// MAX_SPACE 36.0
		};

		int x = compareRoutes(&rt1, &rt2, trucks);

		Assert::AreEqual(1, x);
	}
	// T8F2: Compare two routes when diversion length is equal, and fullness are both equal to 0.
	// Returns 1 if first route has higher priority than second, and 0 otherwise.
	TEST_METHOD(T8F2)
	{
		struct Route rt1 = { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {0,5} }, 6, 'B', '1', 5 };
		struct Route rt2 = { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'Y', '2', 5 };
		struct Truck trucks[] = {
			{ '1', 0, 0.0, 0 },
			{ '2', 0, 0.0, 0 }
			// MAX_WEIGHT 1000
			// MAX_SPACE 36.0
		};

		int x = compareRoutes(&rt1, &rt2, trucks);

		Assert::AreEqual(1, x);
	}
	// T9F2: Compare two routes with no data.
	// Returns 1 if first route has higher priority than second, and 0 otherwise.
	TEST_METHOD(T9F2)
	{
		struct Route rt1 = { {}, 0, '\0', '1', 0 };
		struct Route rt2 = { {}, 0, '\0', '2', 0 };
        struct Truck trucks[] = {
            { '1', 0, 0.0, 0 },
            { '2', 0, 0.0, 0 }
            // MAX_WEIGHT 1000
            // MAX_SPACE 36.0
        };

		int x = compareRoutes(&rt1, &rt2, trucks);

		Assert::AreEqual(1, x);
	}
	// T10F2: Compare two routes based on diversion length where first route is longer than second route, and first route is fuller than second route.
	// Returns 1 if first route has higher priority than second, and 0 otherwise.
	TEST_METHOD(T10F2)
	{
		struct Route rt1 = { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {0,5} }, 6, 'B', '1', 5 };
		struct Route rt2 = { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'Y', '2', 3 };
		struct Truck trucks[] = {
			{ '1', 700, 1.0, 0 },
			{ '2', 300, 1.0, 0 }
			// MAX_WEIGHT 1000
			// MAX_SPACE 36.0
		};

		int x = compareRoutes(&rt1, &rt2, trucks);

		Assert::AreEqual(0, x);
	}
	// T10F2: Compare two routes based on diversion length where first route is longer than second route, and second route is fuller than first route.
	// Returns 1 if first route has higher priority than second, and 0 otherwise.
	TEST_METHOD(T11F2)
	{
		struct Route rt1 = { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {0,5} }, 6, 'B', '1', 5 };
		struct Route rt2 = { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'Y', '2', 3 };
		struct Truck trucks[] = {
			{ '1', 300, 1.0, 0 },
			{ '2', 700, 1.0, 0 }
			// MAX_WEIGHT 1000
			// MAX_SPACE 36.0
		};

		int x = compareRoutes(&rt1, &rt2, trucks);

		Assert::AreEqual(0, x);
	}
	};
    TEST_CLASS(sortRoutes_SHIPPING_module) {
        
    public:
        // T1F3: Sort an array of three valid routes with different lengths based on priority using length.
        // Returns array from highest to lowest priority. //
        TEST_METHOD(T1F3)
        {
            struct Route routes[] = {
                { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'B', '1', 4 },
                { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4} }, 5, 'G', '2', 2 },
                { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {1,4}, {2,4}, {2,5} }, 8, 'Y', '3', 0 }
            };
            struct Truck trucks[] = {
                { '1', 50, 1.0 , 0 },
                { '2', 50, 1.0, 0 },
                { '3', 50, 1.0, 0 }
            };
            
            int numRoutes = 3;
            
            struct Route expectedRoutes[] = {
                { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {1,4}, {2,4}, {2,5} }, 8, 'Y', '3', 0 },
                { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4} }, 5, 'G', '2', 2 },
                { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'B', '1', 4 }
            };
            
            sortRoutes(routes, trucks, numRoutes);
            
            for (int i = 0; i < numRoutes; i++) {
                Assert::AreEqual(expectedRoutes[i].numPoints, routes[i].numPoints);
                Assert::AreEqual(expectedRoutes[i].routeSymbol, routes[i].routeSymbol);
                Assert::AreEqual(expectedRoutes[i].truckSymbol, routes[i].truckSymbol);
                Assert::AreEqual(expectedRoutes[i].diversionLen, routes[i].diversionLen);
            }
        }
        // T2F3: Sort an array of two valid routes with different lengths based on priority using length.
        // Returns array from highest to lowest priority.
        TEST_METHOD(T2F3)
        {
            struct Route routes[] = {
                { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'B', '1', 4 },
                { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4} }, 5, 'G', '2', 2 },
            };
            struct Truck trucks[] = {
                { '1', 50, 1.0 , 0 },
                { '2', 50, 1.0, 0 },
            };
            
            int numRoutes = 2;
            
            struct Route expectedRoutes[] = {
                { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4} }, 5, 'G', '2', 2 },
                { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'B', '1', 4 }
            };
            
            sortRoutes(routes, trucks, numRoutes);
            
            for (int i = 0; i < numRoutes; i++) {
                Assert::AreEqual(expectedRoutes[i].numPoints, routes[i].numPoints);
                Assert::AreEqual(expectedRoutes[i].routeSymbol, routes[i].routeSymbol);
                Assert::AreEqual(expectedRoutes[i].truckSymbol, routes[i].truckSymbol);
                Assert::AreEqual(expectedRoutes[i].diversionLen, routes[i].diversionLen);
            }
        }
        // T3F3: Sort an array of two valid routes with different lengths based on priority using length.
        // Returns array from highest to lowest priority.
        TEST_METHOD(T3F3)
        {
            struct Route routes[] = {
                { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4} }, 5, 'G', '2', 2 },
            };
            struct Truck trucks[] = {
                { '1', 50, 1.0 , 0 },
            };
            
            int numRoutes = 1;
            
            struct Route expectedRoutes[] = {
                { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4} }, 5, 'G', '2', 2 },
            };
            
            sortRoutes(routes, trucks, numRoutes);
            
            for (int i = 0; i < numRoutes; i++) {
                Assert::AreEqual(expectedRoutes[i].numPoints, routes[i].numPoints);
                Assert::AreEqual(expectedRoutes[i].routeSymbol, routes[i].routeSymbol);
                Assert::AreEqual(expectedRoutes[i].truckSymbol, routes[i].truckSymbol);
                Assert::AreEqual(expectedRoutes[i].diversionLen, routes[i].diversionLen);
            }
        }
        // T4F3: Sort an empty array.
        // Returns array from highest to lowest priority.
        TEST_METHOD(T4F3)
        {
            struct Route routes[] = {
                { { }, 0, '\n', '\n', 0 }
            };
            struct Truck trucks[] = {
                { '1', 50, 1.0 , 0 },
            };
            
            int numRoutes = 0;
            
            struct Route expectedRoutes[] = {
                { { }, 0, '\n', '\n', 0 }
            };
            
            sortRoutes(routes, trucks, numRoutes);
            
            for (int i = 0; i < numRoutes; i++) {
                Assert::AreEqual(expectedRoutes[i].numPoints, routes[i].numPoints);
                Assert::AreEqual(expectedRoutes[i].routeSymbol, routes[i].routeSymbol);
                Assert::AreEqual(expectedRoutes[i].truckSymbol, routes[i].truckSymbol);
                Assert::AreEqual(expectedRoutes[i].diversionLen, routes[i].diversionLen);
            }
        }
        // T5F3: Sort an array of three routes all with the same length, and prioritized based on weight and size.
        // Returns array from highest to lowest priority.
        TEST_METHOD(T5F3)
        {
            struct Route routes[] = {
                { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'B', '1', 0 },
                { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4} }, 5, 'G', '2', 0 },
                { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {1,4}, {2,4}, {2,5} }, 8, 'Y', '3', 0 }
            };
            struct Truck trucks[] = {
                { '1', 50, 1.0 , 0 },
                { '2', 25, 1.0, 0 },
                { '3', 50, 1.0, 0 }
            };
            
            int numRoutes = 3;
            
            struct Route expectedRoutes[] = {
                { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4} }, 5, 'G', '2', 0 },
                { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'B', '1', 0 },
                { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {1,4}, {2,4}, {2,5} }, 8, 'Y', '3', 0 }
            };
            
            sortRoutes(routes, trucks, numRoutes);
            
            for (int i = 0; i < numRoutes; i++) {
                Assert::AreEqual(expectedRoutes[i].numPoints, routes[i].numPoints);
                Assert::AreEqual(expectedRoutes[i].routeSymbol, routes[i].routeSymbol);
                Assert::AreEqual(expectedRoutes[i].truckSymbol, routes[i].truckSymbol);
                Assert::AreEqual(expectedRoutes[i].diversionLen, routes[i].diversionLen);
            }
        }
        // T6F3: Sort an array of two routes all with the same length, and prioritized based on weight and size.
        // Returns array from highest to lowest priority.
        TEST_METHOD(T6F3)
        {
            struct Route routes[] = {
                { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'B', '1', 0 },
                { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4} }, 5, 'G', '2', 0 },
            };
            struct Truck trucks[] = {
                { '1', 50, 1.0 , 0 },
                { '2', 25, 1.0, 0 },
            };
            
            int numRoutes = 2;
            
            struct Route expectedRoutes[] = {
                { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4} }, 5, 'G', '2', 0 },
                { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'B', '1', 0 }
            };
            
            sortRoutes(routes, trucks, numRoutes);
            
            for (int i = 0; i < numRoutes; i++) {
                Assert::AreEqual(expectedRoutes[i].numPoints, routes[i].numPoints);
                Assert::AreEqual(expectedRoutes[i].routeSymbol, routes[i].routeSymbol);
                Assert::AreEqual(expectedRoutes[i].truckSymbol, routes[i].truckSymbol);
                Assert::AreEqual(expectedRoutes[i].diversionLen, routes[i].diversionLen);
            }
        }
        // T7F3: Sort an array of three routes that are all equal in length.
        // Returns array from highest to lowest priority.
        TEST_METHOD(T7F3)
        {
            struct Route routes[] = {
                { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'B', '1', 0 },
                { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4} }, 5, 'G', '2', 0 },
                { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {1,4}, {2,4}, {2,5} }, 8, 'Y', '3', 0 }
            };
            struct Truck trucks[] = {
                { '1', 50, 1.0 , 0 },
                { '2', 50, 1.0, 0 },
                { '3', 50, 1.0, 0 }
            };
            
            int numRoutes = 3;
            
            struct Route expectedRoutes[] = {
                { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'B', '1', 0 },
                { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4} }, 5, 'G', '2', 0 },
                { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {1,4}, {2,4}, {2,5} }, 8, 'Y', '3', 0 },
            };
            
            sortRoutes(routes, trucks, numRoutes);
            
            for (int i = 0; i < numRoutes; i++) {
                Assert::AreEqual(expectedRoutes[i].numPoints, routes[i].numPoints);
                Assert::AreEqual(expectedRoutes[i].routeSymbol, routes[i].routeSymbol);
                Assert::AreEqual(expectedRoutes[i].truckSymbol, routes[i].truckSymbol);
                Assert::AreEqual(expectedRoutes[i].diversionLen, routes[i].diversionLen);
            }
        }
        // T8F3: Sort an array of two routes that are all equal in length.
        // Returns array from highest to lowest priority.
        TEST_METHOD(T8F3)
        {
            struct Route routes[] = {
                { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'B', '1', 0 },
                { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4} }, 5, 'G', '2', 0 },
            };
            struct Truck trucks[] = {
                { '1', 50, 1.0 , 0 },
                { '2', 50, 1.0, 0 },
                { '3', 50, 1.0, 0 }
            };
            
            int numRoutes = 2;
            
            struct Route expectedRoutes[] = {
                { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'B', '1', 0 },
                { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4} }, 5, 'G', '2', 0 },
            };
            
            sortRoutes(routes, trucks, numRoutes);
            
            for (int i = 0; i < numRoutes; i++) {
                Assert::AreEqual(expectedRoutes[i].numPoints, routes[i].numPoints);
                Assert::AreEqual(expectedRoutes[i].routeSymbol, routes[i].routeSymbol);
                Assert::AreEqual(expectedRoutes[i].truckSymbol, routes[i].truckSymbol);
                Assert::AreEqual(expectedRoutes[i].diversionLen, routes[i].diversionLen);
            }
        }
    };
    TEST_CLASS(copyRoute_SHIPPING_module) {
    public:
        // T1F4: Copy a valid route from source to empty destination
        TEST_METHOD(T1F4)
        {
            
            struct Route src = { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'B', '2', 0 };
            struct Route dest = { {}, 0, '\0', '\0', 0 };
            
            copyRoute(&dest, &src);
            
            Assert::AreEqual(src.numPoints, dest.numPoints);
            Assert::AreEqual(src.routeSymbol, dest.routeSymbol);
            Assert::AreEqual(src.truckSymbol, dest.truckSymbol);
            Assert::AreEqual(src.diversionLen, dest.diversionLen);
            for (int i = 0; i < dest.numPoints; i++) {
                Assert::AreEqual(src.points[i].row, dest.points[i].row);
                Assert::AreEqual(src.points[i].col, dest.points[i].col);
            }
        }
        // Copy a valid route from source to non-empty destination
        TEST_METHOD(T2F4)
        {
            
            struct Route src = { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'B', '2', 0 };
            struct Route dest = { { {1,2}, {1,3}, {1,4} }, 0, '\0', '\0', 0 };
            
            copyRoute(&dest, &src);
            
            Assert::AreEqual(src.numPoints, dest.numPoints);
            Assert::AreEqual(src.routeSymbol, dest.routeSymbol);
            Assert::AreEqual(src.truckSymbol, dest.truckSymbol);
            Assert::AreEqual(src.diversionLen, dest.diversionLen);
            for (int i = 0; i < dest.numPoints; i++) {
                Assert::AreEqual(src.points[i].row, dest.points[i].row);
                Assert::AreEqual(src.points[i].col, dest.points[i].col);
            }
        }
        // Copy an empty route from source to non-empty destination
        TEST_METHOD(T3F4)
        {
            
            struct Route src = { {}, 0, '\0', '\0', 0 };
            struct Route dest = { { {1,2}, {1,3}, {1,4} }, 0, '\0', '\0', 0 };
            
            copyRoute(&dest, &src);
            
            Assert::AreEqual(src.numPoints, dest.numPoints);
            Assert::AreEqual(src.routeSymbol, dest.routeSymbol);
            Assert::AreEqual(src.truckSymbol, dest.truckSymbol);
            Assert::AreEqual(src.diversionLen, dest.diversionLen);
            for (int i = 0; i < dest.numPoints; i++) {
                Assert::AreEqual(src.points[i].row, dest.points[i].row);
                Assert::AreEqual(src.points[i].col, dest.points[i].col);
            }
        }
        // Copy an empty route from source to empty destination.
        TEST_METHOD(T4F4)
        {
            
            struct Route src = { {}, 0, '\0', '\0', 0 };
            struct Route dest = { {}, 0, '\0', '\0', 0 };
            
            copyRoute(&dest, &src);
            
            Assert::AreEqual(src.numPoints, dest.numPoints);
            Assert::AreEqual(src.routeSymbol, dest.routeSymbol);
            Assert::AreEqual(src.truckSymbol, dest.truckSymbol);
            Assert::AreEqual(src.diversionLen, dest.diversionLen);
            for (int i = 0; i < dest.numPoints; i++) {
                Assert::AreEqual(src.points[i].row, dest.points[i].row);
                Assert::AreEqual(src.points[i].col, dest.points[i].col);
            }
        }
        
    };
    TEST_CLASS(addPackage_SHIPPING_module) {
    public:
        // T1F5: Add a package within the space and weight limits to a truck.
        // Return 1 on success, 0 if package was not added.
        TEST_METHOD(T1F5)
        {
            struct Package package = { 1.0, 50, {} };
            struct Truck truck = { '1', 100, 20.0, 0 };
            
            //MAX_WEIGHT = 1000;
            // MAX_SPACE = 36.0;
            
            int result = addPackage(&package, &truck);
            Assert::AreEqual(1, result);
        }
        // T2F5: Add a package with space exceeding the limit of a truck.
        // Return 1 on success, 0 if package was not added.
        TEST_METHOD(T2F5)
        {
            struct Package package = { 1.0, 50, {} };
            struct Truck truck = { '1', 100, 36.0, 0 };
            
            //MAX_WEIGHT = 1000;
            // MAX_SPACE = 36.0;
            
            int result = addPackage(&package, &truck);
            Assert::AreEqual(0, result);
        }
        // T3F5: Add a package with weight exceeding the limit of a truck.
        // Return 1 on success, 0 if package was not added.
        TEST_METHOD(T3F5)
        {
            struct Package package = { 1.0, 50, {} };
            struct Truck truck = { '1', 975, 30.0, 0 };
            
            //MAX_WEIGHT = 1000;
            // MAX_SPACE = 36.0;
            
            int result = addPackage(&package, &truck);
            Assert::AreEqual(0, result);
        }
        // Add a package with both space and weight exceeding the limit of a truck.
        // Return 1 on success, 0 if package was not added.
        TEST_METHOD(T4F5)
        {
            struct Package package = { 1.0, 50, {} };
            struct Truck truck = { '1', 975, 35.0, 0 };
            
            //MAX_WEIGHT = 1000;
            // MAX_SPACE = 36.0;
            
            int result = addPackage(&package, &truck);
            Assert::AreEqual(0, result);
        }
        // Add a package to a truck that is already full.
        // Return 1 on success, 0 if package was not added.
        TEST_METHOD(T5F5)
        {
            struct Package package = { 1.0, 50, {} };
            struct Truck truck = { '1', 1000, 36.0, 0 };
            
            //MAX_WEIGHT = 1000;
            // MAX_SPACE = 36.0;
            
            int result = addPackage(&package, &truck);
            Assert::AreEqual(0, result);
        }
        
        
    };
    TEST_CLASS(getFullness_SHIPPING_module) {
        
    public:
        // T1F6: Correctly return how full a truck is in percentage when truck is empty.
        // Returns how full a truck is as a perctange.
        TEST_METHOD(T1F6)
        {
            struct Truck truck = { 'B', 0, 0, 0 };
            //MAX_WEIGHT = 1000;
            //MAX_SPACE = 36.0;
            
            double fullness = getFullness(&truck);
            
            Assert::AreEqual(0.0, fullness);
        }
        // T2F6: Correctly return how full a truck is in percentage when truck is full by weight.
        // Returns how full a truck is as a perctange.
        TEST_METHOD(T2F6)
        {
            struct Truck truck = { 'B', 1000, 0, 1 };
            //MAX_WEIGHT = 1000;
            //MAX_SPACE = 36.0;
            
            double fullness = getFullness(&truck);
            
            Assert::AreEqual(100.0, fullness);
        }
        // T3F6: Correctly return how full a truck is in percentage when truck is full by size.
        // Returns how full a truck is as a perctange.
        TEST_METHOD(T3F6)
        {
            struct Truck truck = { 'B', 0, 36, 1 };
            //MAX_WEIGHT = 1000;
            //MAX_SPACE = 36.0;
            
            double fullness = getFullness(&truck);
            
            Assert::AreEqual(100.0, fullness);
        }
        // T4F6: Correctly return how full a truck is based on the limiting factor of either weight or space, in this case weight.
        // Returns how full a truck is as a percentage.
        TEST_METHOD(T4F6)
        {
            struct Truck truck = { 'B', 800, 20.0, 0 };
            //MAX_WEIGHT = 1000;
            //MAX_SPACE = 36.0;
            
            double fullness = getFullness(&truck);
            
            Assert::AreEqual(80.0, fullness);
        }
        // T5F6: Correctly return how full a truck is based on the limiting factor of either weight or space, in this case space.
        // Returns how full a truck is as a percentage.
        TEST_METHOD(T5F6)
        {
            struct Truck truck = { 'B', 20, 27.0, 0 };
            //MAX_WEIGHT = 1000;
            //MAX_SPACE = 36.0;
            
            double fullness = getFullness(&truck);
            
            Assert::AreEqual(75.0, fullness);
        }
        // T6F6: Correctly return how a full truck is when both weight and space are equally full.
        // Returns how full a truck is as a percentage.
        TEST_METHOD(T6F6)
        {
            struct Truck truck = { 'B', 500, 18.0, 0 };
            //MAX_WEIGHT = 1000;
            //MAX_SPACE = 36.0;
            
            double fullness = getFullness(&truck);
            
            Assert::AreEqual(50.0, fullness);
        }
        
    };

}

namespace IntegrationTest
{

	TEST_CLASS(sortRoutes_compareRoutes)
    {
    public:
        // Integration test to ensure 'sortRoutes' and 'compareRoutes' are working correctly with two routes and two trucks, based on weight.
        TEST_METHOD(IT1_1)
        {
            
            struct Route routes[] = {
                { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'B', '1', 0 },
                { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4} }, 5, 'G', '2', 0 }
            };
            
            struct Truck trucks[] = {
                { '1', 50, 1.0 , 0 },
                { '2', 25, 1.0, 0 },
            };
            int numRoutes = 2;
            
            int x = compareRoutes(&routes[0], &routes[1], trucks);
            Assert::AreEqual(0, x);
            
            
            sortRoutes(routes, trucks, numRoutes);
            Assert::AreEqual(routes[0].routeSymbol, 'G');
            Assert::AreEqual(routes[1].routeSymbol, 'B');
        }
        
        // Integration test to ensure 'sortRoutes' and 'compareRoutes' are working correctly with two routes and two trucks, when both are equal length, size and weight.
        TEST_METHOD(IT1_2)
        {
            
            struct Route routes[] = {
                { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'B', '1', 0 },
                { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4} }, 5, 'G', '2', 0 }
            };
            
            struct Truck trucks[] = {
                { '1', 50, 1.0 , 0 },
                { '2', 50, 1.0, 0 },
            };
            int numRoutes = 2;
            
            int x = compareRoutes(&routes[0], &routes[1], trucks);
            Assert::AreEqual(1, x);
            
            
            sortRoutes(routes, trucks, numRoutes);
            Assert::AreEqual(routes[0].routeSymbol, 'B');
            Assert::AreEqual(routes[1].routeSymbol, 'G');
        }
        
        // Integration test to ensure 'sortRoutes' and 'compareRoutes' are working correctly with two routes and two trucks, based on size.
        TEST_METHOD(IT1_3)
        {
            
            struct Route routes[] = {
                { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'B', '1', 0 },
                { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4} }, 5, 'G', '2', 0 }
            };
            
            struct Truck trucks[] = {
                { '1', 50, 3.0 , 0 },
                { '2', 50, 1.0, 0 },
            };
            int numRoutes = 2;
            
            int x = compareRoutes(&routes[0], &routes[1], trucks);
            Assert::AreEqual(0, x);
            
            
            sortRoutes(routes, trucks, numRoutes);
            Assert::AreEqual(routes[0].routeSymbol, 'G');
            Assert::AreEqual(routes[1].routeSymbol, 'B');
        }
        
        //Integration test to ensure 'sortRoutes' and 'compareRoutes' are working correctly with two routes and two trucks, based on diversion length.
        TEST_METHOD(IT1_4)
        {
            
            struct Route routes[] = {
                { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'B', '1', 2 },
                { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4} }, 5, 'G', '2', 0 }
            };
            
            struct Truck trucks[] = {
                { '1', 50, 1.0 , 0 },
                { '2', 50, 1.0, 0 },
            };
            int numRoutes = 2;
            
            int x = compareRoutes(&routes[0], &routes[1], trucks);
            Assert::AreEqual(0, x);
            
            
            sortRoutes(routes, trucks, numRoutes);
            Assert::AreEqual(routes[0].routeSymbol, 'G');
            Assert::AreEqual(routes[1].routeSymbol, 'B');
        }
        
    };


	TEST_CLASS(compareRoutes_getFullness)
	{
	public:
		// Integration test to ensure 'compareRoutes' and 'getFullness' are working correctly when diversion length is equal, but second truck is fuller than first truck in terms of weight.
		TEST_METHOD(IT2_1)
		{
			struct Route rt1 = { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {0,5} }, 6, 'B', '1', 5 };
			struct Route rt2 = { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'Y', '2', 5 };
			struct Truck trucks[] = {
				{ '1', 300, 1.0, 0 },
				{ '2', 800, 1.0, 0 }
				// MAX_WEIGHT 1000
				// MAX_SPACE 36.0
			};

			double fullness1 = getFullness(&trucks[0]);
			double fullness2 = getFullness(&trucks[1]);
			Assert::IsTrue(fullness1 < fullness2);


			int x = compareRoutes(&rt1, &rt2, trucks);

			Assert::AreEqual(1, x);
		}

		// Integration test to ensure 'compareRoutes' and 'getFullness' are working correctly when diversion length is equal, but first truck is fuller than second truck in terms of weight.
		TEST_METHOD(IT2_2)
		{
			struct Route rt1 = { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {0,5} }, 6, 'B', '1', 5 };
			struct Route rt2 = { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'Y', '2', 5 };
			struct Truck trucks[] = {
				{ '1', 800, 1.0, 0 },
				{ '2', 300, 1.0, 0 }
				// MAX_WEIGHT 1000
				// MAX_SPACE 36.0
			};

			double fullness1 = getFullness(&trucks[0]);
			double fullness2 = getFullness(&trucks[1]);
			Assert::IsTrue(fullness1 > fullness2);


			int x = compareRoutes(&rt1, &rt2, trucks);

			Assert::AreEqual(0, x);
		}

		// Integration test to ensure 'compareRoutes' and 'getFullness' are working correctly when diversion length is equal, but first truck is fuller than second truck in terms of size.
		TEST_METHOD(IT2_3)
		{
			struct Route rt1 = { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {0,5} }, 6, 'B', '1', 5 };
			struct Route rt2 = { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'Y', '2', 5 };
			struct Truck trucks[] = {
				{ '1', 100, 18.0, 0 },
				{ '2', 100, 1.0, 0 }
				// MAX_WEIGHT 1000
				// MAX_SPACE 36.0
			};

			double fullness1 = getFullness(&trucks[0]);
			double fullness2 = getFullness(&trucks[1]);
			Assert::IsTrue(fullness1 > fullness2);


			int x = compareRoutes(&rt1, &rt2, trucks);

			Assert::AreEqual(0, x);
		}
		// Integration test to ensure 'compareRoutes' and 'getFullness' are working correctly when diversion length is equal, but second truck is fuller than first truck in terms of size.
		TEST_METHOD(IT2_4)
		{
			struct Route rt1 = { { {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {0,5} }, 6, 'B', '1', 5 };
			struct Route rt2 = { { {0,0}, {0,1}, {0,2}, {1,2}, {1,3}, {1,4} }, 6, 'Y', '2', 5 };
			struct Truck trucks[] = {
				{ '1', 100, 1.0, 0 },
				{ '2', 100, 18.0, 0 }
				// MAX_WEIGHT 1000
				// MAX_SPACE 36.0
			};

			double fullness1 = getFullness(&trucks[0]);
			double fullness2 = getFullness(&trucks[1]);
			Assert::IsTrue(fullness1 < fullness2);


			int x = compareRoutes(&rt1, &rt2, trucks);

			Assert::AreEqual(1, x);
		}

	};


    TEST_CLASS(validatePackageInfo_convertToPoint) {
    public:
        //T1: Integration test to ensure validatePackageInfo and convertToPoint are working with input of valid weight, size, and destination
        TEST_METHOD(IT3_1)
        {
            int weight = 200;
            double size = 0.25;
            char* dest = "12B";
            int inputValidity = validatePackageInfo(&weight, &size, dest);
            Assert::AreEqual(1, inputValidity);
            if (inputValidity == 1)
            {
                struct Point expectedPoint = { 11,1 };
                struct Point actualPoint = convertToPoint(dest);
                Assert::AreEqual(expectedPoint.row, actualPoint.row);
                Assert::AreEqual(expectedPoint.col, actualPoint.col);
            }
        }
        
        //T2: Integration test to ensure validatePackageInfo and convertToPoint are working with input of invalid weight but valid size, and destination
        TEST_METHOD(IT3_2)
        {
            int weight = 2000;
            double size = 0.25;
            char* dest = "12B";
            int inputValidity = validatePackageInfo(&weight, &size, dest);
            Assert::AreEqual(0, inputValidity);
            if (inputValidity == 0)
            {
                struct Point expectedPoint = { 11,1 };
                struct Point actualPoint = convertToPoint(dest);
                Assert::AreEqual(expectedPoint.row, actualPoint.row);
                Assert::AreEqual(expectedPoint.col, actualPoint.col);
            }
        }
        
        //T3: Integration test to ensure validatePackageInfo and convertToPoint are working with input of invalid destination but valid size, and weight
        TEST_METHOD(IT3_3)
        {
            int weight = 200;
            double size = 0.25;
            char* dest = "27Z";
            int inputValidity = validatePackageInfo(&weight, &size, dest);
            Assert::AreEqual(0, inputValidity);
            if (inputValidity == 0)
            {
                struct Point expectedPoint = { -1,-1 };
                struct Point actualPoint = convertToPoint(dest);
                Assert::AreEqual(expectedPoint.row, actualPoint.row);
                Assert::AreEqual(expectedPoint.col, actualPoint.col);
            }
        }
        
        //T4: Integration test to ensure validatePackageInfo and convertToPoint are working with input of invalid size but valid destination, and weight
        TEST_METHOD(IT3_4)
        {
            int weight = 200;
            double size = 1.5;
            char* dest = "12B";
            int inputValidity = validatePackageInfo(&weight, &size, dest);
            Assert::AreEqual(0, inputValidity);
            if (inputValidity == 0)
            {
                struct Point expectedPoint = { 11,1 };
                struct Point actualPoint = convertToPoint(dest);
                Assert::AreEqual(expectedPoint.row, actualPoint.row);
                Assert::AreEqual(expectedPoint.col, actualPoint.col);
            }
        }
    };


    TEST_CLASS(validateDestination_ConvertToPoint) {
    public:
        //T1: Integration test to make sure validateDestination and convertToPoint are working with input of valid destination
        TEST_METHOD(IT4_1)
        {
            char* dest = "12B";
            int inputValidity = validateDestination(dest);
            Assert::AreEqual(1, inputValidity);
            if (inputValidity == 1)
            {
                struct Point expectedPoint = { 11,1 };
                struct Point actualPoint = convertToPoint(dest);
                Assert::AreEqual(expectedPoint.row, actualPoint.row);
                Assert::AreEqual(expectedPoint.col, actualPoint.col);
            }
            
        }
        //T2: Integration test to make sure validateDestination and convertToPoint are working with input of invalid destination where the column number exceeds the map
        TEST_METHOD(IT4_2)
        {
            char* dest = "12Z";
            int inputValidity = validateDestination(dest);
            Assert::AreEqual(0, inputValidity);
            if (inputValidity == 0)
            {
                struct Point expectedPoint = { -1,-1 };
                struct Point actualPoint = convertToPoint(dest);
                Assert::AreEqual(expectedPoint.row, actualPoint.row);
                Assert::AreEqual(expectedPoint.col, actualPoint.col);
            }
            
        }
        //T3: Test for invalid input with expected invalid point
        TEST_METHOD(IT4_3)
        {
            char* dest = "X";
            int inputValidity = validateDestination(dest);
            Assert::AreEqual(0, inputValidity);
            if (inputValidity == 0)
            {
                struct Point expectedPoint = { -1,-1 };
                struct Point actualPoint = convertToPoint(dest);
                Assert::AreEqual(expectedPoint.row, actualPoint.row);
                Assert::AreEqual(expectedPoint.col, actualPoint.col);
            }
            
        }
        //T4: Test for invalid input with expected invalid point
        TEST_METHOD(IT4_4)
        {
            char* dest = "123";
            int inputValidity = validateDestination(dest);
            Assert::AreEqual(0, inputValidity);
            if (inputValidity == 0)
            {
                struct Point expectedPoint = { -1,-1 };
                struct Point actualPoint = convertToPoint(dest);
                Assert::AreEqual(expectedPoint.row, actualPoint.row);
                Assert::AreEqual(expectedPoint.col, actualPoint.col);
            }
            
        }
        //T5: Integration test to make sure validateDestination and convertToPoint are working with input of invalid destination where the row number exceeds the map
        TEST_METHOD(IT4_5)
        {
            char* dest = "27X";
            int inputValidity = validateDestination(dest);
            Assert::AreEqual(0, inputValidity);
            if (inputValidity == 0)
            {
                struct Point expectedPoint = { -1,-1 };
                struct Point actualPoint = convertToPoint(dest);
                Assert::AreEqual(expectedPoint.row, actualPoint.row);
                Assert::AreEqual(expectedPoint.col, actualPoint.col);
            }
            
        }
    };


    TEST_CLASS(ValidatePackageInfo_validateDestination) {
    public:
        // T1: Integration test to make sure validateDestination and validatePackageInfo are working with input of valid weight, size, and destination
        TEST_METHOD(IT5_1)
        {
            int weight = 200;
            double size = 0.25;
            char* dest = "12B";
            int inputValidity = validatePackageInfo(&weight, &size, dest);
            Assert::AreEqual(1, inputValidity);
            int destValidity = validateDestination(dest);
            Assert::AreEqual(1, destValidity);
        }
        
        // T2: Integration test to make sure validateDestination and validatePackageInfo are working with input of valid size, and destination but invalid weight
        TEST_METHOD(IT5_2)
        {
            int weight = 2000;
            double size = 0.25;
            char* dest = "12B";
            int inputValidity = validatePackageInfo(&weight, &size, dest);
            Assert::AreEqual(0, inputValidity);
            int destValidity = validateDestination(dest);
            Assert::AreEqual(1, destValidity);
        }
        
        // T3: Integration test to make sure validateDestination and validatePackageInfo are working with input of valid weight, and size but invalid destination
        TEST_METHOD(IT5_3)
        {
            int weight = 200;
            double size = 0.25;
            char* dest = "27X";
            int inputValidity = validatePackageInfo(&weight, &size, dest);
            Assert::AreEqual(0, inputValidity);
            int destValidity = validateDestination(dest);
            Assert::AreEqual(0, destValidity);
        }
        
        // T4: Integration test to make sure validateDestination and validatePackageInfo are working with input of valid weight, and destination but invalid size
        TEST_METHOD(IT5_4)
        {
            int weight = 200;
            double size = 1.5;
            char* dest = "1A";
            int inputValidity = validatePackageInfo(&weight, &size, dest);
            Assert::AreEqual(0, inputValidity);
            int destValidity = validateDestination(dest);
            Assert::AreEqual(1, destValidity);
        }
    };
}
