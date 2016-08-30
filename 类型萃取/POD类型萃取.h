
struct TrueType
{
	bool Get()
	{
		return true;
	}
};
struct FalseType
{
	bool Get()
	{
		return false;
	}
};

template <class T>
struct TypeTraits
{
	typedef FalseType IsPODType; //Ç¶Ì×ÀàĞÍÉùÃ÷
};

template <>
struct TypeTraits<int>
{
	typedef TrueType IsPODType; 
};

template<>
struct TypeTraits<double>
{
	typedef TrueType IsPODType;
};


