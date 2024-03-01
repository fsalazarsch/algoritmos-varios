
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
		
		//auto itBegin = m_map.lower_bound(keyBegin);
		//auto itEnd = m_map.lower_bound(keyEnd)
		
		if (!( keyBegin < keyEnd )) return ;
		
		typename std::map<K,V>::iterator itBegin = m_map.lower_bound(keyBegin);
		//auto itBegin = m_map.lower_bound(keyBegin);
		
		if ((itBegin == m_map.begin()) && ((--itBegin)->second == val)){
			++itBegin;
		}
		
		typename std::map<K,V>::iterator itEnd = m_map.lower_bound(keyEnd);
		//auto itEnd = m_map.lower_bound(keyEnd)
		if (itEnd != m_map.end() && itEnd->first == keyEnd) {
			++itEnd;
		}
		
		m_map.erase(itBegin, itEnd);
		
		if (val != m_valBegin){
			m_map[keyBegin] = val;
		}

	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		
		typename std::map<K,V>::iterator it = m_map.upper_bound(key);
		//auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.
