//
// Created by hikarido on 6/24/18.
//

// Section implementation of multipliction

/**
 *
 * @tparam First type whick can be multiplied
 * @tparam Second type which can be multiplied
 * @param lhs lhs * rhd
 * @param rhs lhs * rhs
 * @return new pair which is multiplied result of lhs and rhs
 */
template<typename First, typename Second>
pair<First, Second> operator*(pair<First, Second> & lhs, pair<First, Second> & rhs){
	lhs.first = lhs.first * rhs.first;
	lhs.second = lhs.second * rhs.second;
	return lhs;
};

/**
 * Возведение в степень 2 элементов вектора vec
 * @tparam MultipliedItem type which can be multiplied
 * @param vec std::vector
 * @return changed vector
 */
template<typename MultipliedItem>
vector<MultipliedItem> & power2(vector<MultipliedItem> & vec){
	for(auto & item: vec){
		item = item * item;
	}

	return vec;
}

/**
 * Возводит в степень 2 значения карты dict
 * @tparam Key ключ карты
 * @tparam Value знчение карты
 * @param dict std::map
 * @return карту с возведёнными в квадрат значениями
 */
template<typename Key, typename Value>
map<Key, Value> & power2(map<Key, Value> & dict){
	for(auto & item: dict){
		item.second = item.second * item.second;
	}

	return dict;
}

/**
 * Оператор умножение для vector, предпалагается, что будет использоваться тольк для возведения в степень
 * Тоесть lhs and rhs is equal all time
 * @tparam MultipliedItem элемент который поддерживает умножение
 * @param lhs std::vector
 * @param rhs std::vector
 * @return lhs*rhs elementwise
 */
template<typename MultipliedItem>
vector<MultipliedItem> & operator * (vector<MultipliedItem> & lhs, vector<MultipliedItem> & rhs){
	assert(lhs.size() == rhs.size());
	for(size_t i = 0; i < lhs.size(); ++i){
		lhs[i] = lhs[i] * rhs[i];
	}

	return lhs;
}

/**
 * Оператор умножения для map предполагается, что будет использоваться только для возведения в степень
 * тоесть lhs equal rhs all time
 * В степень возводятся только ключи
 * @tparam Key ключ карты
 * @tparam Value значение картыЮ кторое поддердивает operator *
 * @param lhs std::map
 * @param rhs std::map
 * @return
 * lhs second элементов которого умножены на second элементов rhs
 */
template<typename Key,typename Value>
map<Key, Value> & operator * (map<Key, Value> & lhs, map<Key, Value> & rhs){
	assert(lhs.size() == rhs.size());

	auto lhs_iter = lhs.begin();
	auto rhs_iter = rhs.begin();

	for(;lhs_iter != lhs.end(); ++lhs_iter, ++rhs_iter){
		lhs_iter->second = lhs_iter->second * rhs_iter->second;
	}

	return lhs;
};

// End section implementation of multiply

// Section for testing multiply section
void test_pair_multiplying(){
	{
		pair<int, int> p = {1,1};
		auto pow2p = p * p;
		assert(pow2p == std::make_pair(1,1));
	}

	{
		pair<int, double> p = {3, 9.0};
		assert((p*p) == std::make_pair(9, 81.0));
	}

	{
		pair<double, int> p = {-1, 0};
		auto p2 = std::make_pair<double, int>(1, 0);
		assert((p*p) == p2);
	}

	{
		pair<pair<int, int>, int> p = {{2,3}, 4};
		assert((p*p) == std::make_pair(std::make_pair(4,9), 16));
	}

	{
		pair<int, pair<int, int>> p = {2, {3,4}};
		assert((p*p) == std::make_pair(4, std::make_pair(9, 16)));
	}

	{
		pair<pair<int,int>, pair<int, int>> p = {{2,3}, {4,5}};
		pair<pair<int, int> ,pair<int, int>> ans = {{4, 9}, {16, 25}};
		assert((p*p) == ans);
	}

	{
		pair<int, vector<int>> p = {2, {2,3,4}};
		decltype(p) ans = {4, {4, 9, 16}};
		assert((p*p) == ans);
	}
}

void test_map_multiplying(){
	{
		map<int, int> m;
		map<int, int> ans;
		assert((m*m) == ans);
	}
	{
		map<int, int> m = {{1, 2}, {3,4}};
		map<int, int> ans = {{1,4}, {3, 16}};
		assert((m * m) == ans);
	}

	{
		map<int, map<int, int>> m = {{3, {{3,10}}}};
		decltype(m) ans = {{3, {{3, 100}}}};
		assert((m*m) == ans);
	}

	{
		map<int, pair<int, int>> m = {{2, {3,4}}};
		map<int, pair<int, int>> ans = {{2, {9, 16}}};
		assert((m*m) == ans);
	}

	{
		map<pair<int,int>, int> m = {{{2,3}, 3}};
		decltype(m) ans = {{{2,3}, 9}};
		assert((m*m) == ans);
	}

	{
		map<int, pair<int, int>> m = {{2, {3 ,4}}};
		map<int, pair<int, int>> ans = {{2, {9, 16}}};
		assert((m*m) == ans);
	}

	{
		map<pair<int, int>, pair<int, int>> m = {{{-2,3}, {3,-4}}};
		decltype(m) ans = {{{-2,3}, {9, 16}}};
		assert((m*m) == ans);
	}

	{
		map<vector<int>, int> m = {{{1,2,3}, 3}, {{22,11}, 4}};
		decltype(m) ans = {{{1,2,3}, 9}, {{22,11}, 16}};
		assert((m*m) == ans);
	}

	{
		map<int, vector<int>> m = {{4, {1,2,3}}, {5, {2,3,-4}}};
		map<int, vector<int>> ans = {{4, {1,4,9}}, {5, {4, 9, 16}}};
		assert((m*m) == ans);
	}

	{
		map<vector<int>, vector<int>> m = {{{1,2,3}, {2,3}}, {{2,3}, {3, 4, 5}}};
		decltype(m) ans = {{{1,2,3}, {4,9}}, {{2,3}, {9, 16,25}}};
		assert((m*m) == ans);
	}


//	map as key, No iam not do this....
//	{
//		map<map<int, int>, int> m = {{{2,4}, 3}};
//		decltype(m) ans = {{{{2, 16}}, 9}};
//		assert((m*m) == ans);
//
//
//	}


}

void test_vector_multiplying(){
	{
		vector<int> v;
		assert((v*v) == v);
	}

	{
		vector<int> v = {1,2,3,4,5};
		vector<int> ans = {1,4,9,16,25};
		assert((v*v) == ans);
	}

	{
		vector<pair<int, int>> v = {{1,2}, {3,4}};
		decltype(v) ans = {{1,4}, {9, 16}};
		assert((v*v) == ans);
	}

	{
		vector<vector<int>> v = {{1,2,3}, {3,4,5}};
		decltype(v) ans = {{1, 4, 9}, {9,16, 25}};
		assert((v*v) == ans);
	}

	{
		vector<vector<pair<int, int>>> v = {{{2,3}, {3, 4}}};
		decltype(v) ans = {{{4, 9}, {9, 16}}};
		assert((v*v) == ans);
	}

	{
		vector<vector<pair<int, vector<int>>>> v = {{{2, {2,3,4}}, {3, {1,2,3}}}};
		decltype(v) ans = {{{4, {4, 9, 16}}, {9, {1,4,9}}}};
		assert((v*v) == ans);
	}
}

void test_collection_multiplying(){
	{
		vector<int> v = {-1,2,3, 0};
		v = power2(v);
		vector<int> ans = {1, 4, 9, 0};
		assert(v == ans);
	}

	{
		map<int, vector<pair<int, int>>> m = {
				{1, {{1,2},{2,2},{3,3}}},
				{2, {{-1, -1}, {0,0}, {2,2}}},
				{3, {{1,2}}}
		};

		decltype(m) ans = {
				{1, {{1, 4}, {4, 4}, {9, 9}}},
				{2, {{1, 1}, {0,0}, {4,4}}},
				{3, {{1,4}}}
		};
		assert((power2(m)) == ans);
	}

}

void test_power_and_multiply(){
	test_pair_multiplying();
	test_map_multiplying();
	test_vector_multiplying();
	test_collection_multiplying();
}
// End section for testing implementation of multiply