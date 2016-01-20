# dasom_seminar
For dasom seminar repositiry (Kyunghee Univ)

# template <typename Cl_keyType, typename Cl_valueType> class ClMap
{
private:
	ClPair<Cl_keyType, Cl_valueType>* pPairs;
	int cPairs;
public:
	ClMap();
	void insert(ClPair<Cl_keyType, Cl_valueType>& Cl_element);
	Cl_valueType at(Cl_keyType Cl_key);
	bool empty();
	int size() { return cPairs; }
	Cl_valueType& operator[](Cl_keyType Cl_key);
	void operator=(ClMap<Cl_keyType, Cl_valueType> Cl_Map);
};

# template <typename Cl_firstType, typename Cl_secondType> class ClPair
{
private:
	Cl_firstType Cl_first;
	Cl_secondType Cl_second;
public:
	ClPair() {}
	ClPair(Cl_firstType Cl_first, Cl_secondType Cl_second);
	Cl_firstType& first() { return Cl_first; }
	Cl_secondType& second() { return Cl_second; }
};
