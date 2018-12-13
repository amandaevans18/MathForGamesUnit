#pragma once
#include<iostream>

bool assertTrue(const char* testName, bool expression);

bool assertEqual(const char* testName, int expected, int actual);

bool assertNearEqual(const char* testName, float expected, float actual, float tolerance);

