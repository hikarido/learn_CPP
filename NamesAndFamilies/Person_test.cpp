//
// Created by hikarido on 7/2/18.
//

#include "gtest/gtest.h"
#include "Person.h"

TEST(Person, Setters){
	Person p{};
	ASSERT_EQ(p.getFullName(1456), "testing");

}





