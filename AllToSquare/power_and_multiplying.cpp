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

