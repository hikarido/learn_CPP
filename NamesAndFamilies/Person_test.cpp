//
// Created by hikarido on 7/2/18.
//

#include "gtest/gtest.h"
#include "Person.h"

TEST(Person, TaskTest){
	Person person{};
	person.changeFirstName(1965, "Polina");
	person.changeLastName(1967, "Sergeeva");

	ASSERT_EQ(person.getFullName(1900), "Incognito");
	ASSERT_EQ(person.getFullName(1965), "Polina with unknown last name");
	ASSERT_EQ(person.getFullName(1990), "Polina Sergeeva");

	person.changeFirstName(1970, "Appolinaria");
	ASSERT_EQ(person.getFullName(1969), "Polina Sergeeva");
	ASSERT_EQ(person.getFullName(1970), "Appolinaria Sergeeva");

	person.changeLastName(1968, "Volkova");
	ASSERT_EQ(person.getFullName(1969), "Polina Volkova");
	ASSERT_EQ(person.getFullName(1970), "Appolinaria Volkova");


}





