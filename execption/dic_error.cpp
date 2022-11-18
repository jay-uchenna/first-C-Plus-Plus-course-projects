#include <iostream>
#include <map>
#include <exception>

//Dictionary interface
template<class Key, class Value>
class dictionary
{
public:
    virtual ~dictionary() = default;

    virtual const Value& get(const Key& key) const = 0;
    virtual void set(const Key& key, const Value& value) = 0;
    virtual bool is_set(const Key& key) const = 0;
};

//Dictionary exception interface
template<class Key>
class not_found_exception : public std::exception
{
public:
    virtual const Key& get_key() const noexcept = 0;
};
//Implimentation of dictionary excption class
//Tells you what key caused does no exist
template<class Key>
class no_such_key_exception : public not_found_exception<Key> 
{
public:
	no_such_key_exception(const Key& key) : m_key(key) { }
	const Key& get_key() const noexcept override
	{
		return this->m_key;
	}
	const char* what() const noexcept override 
	{
		return "key not found in dictionary"; 
	}

private:
	Key m_key;
};
//dictionary  class with get, set and is set functions
template<class Key, class Value>
class data_dictionary : public dictionary<Key, Value>
{
public:
	const Value& get(const Key& key) const override 
	{
		typename std::map<Key, Value>::const_iterator it = this->m_data.find(key);
		if (it == this->m_data.end())
		{
			throw no_such_key_exception<Key>(key);
		}
		return it->second;
	}

	void set(const Key& key, const Value& value) override
	{
		this->m_data[key] = value;
	}

	bool is_set(const Key& key) const override 
	{
		return this->m_data.find(key) != this->m_data.end();
	}

private:
	std::map<Key, Value> m_data;
};
