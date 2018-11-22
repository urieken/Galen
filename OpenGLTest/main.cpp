#include "application.h"

#include <map>

class A {
	unsigned int m_value;
public:
	A() : m_value{ 0 } {}
	virtual ~A() {}

	void SetValue(const unsigned int value) {
		m_value = value;
	}

	const unsigned int GetValue() const {
		return m_value;
	}
};

typedef struct _component {
	const A& AInstance;
}Component;

std::map<unsigned int, Component> Components;

void InsertComponent(std::map<unsigned int, Component>& list, const unsigned int id, const Component& component) {
	list.insert(std::make_pair(id, component));
}

int main(int argc, char** argv) {
	int nReturn{ 0 };

	Logger::Instance().Initialize();
	std::map<unsigned int, Component> list;
	A a, b, c;
	
	a.SetValue(0);
	b.SetValue(2);
	c.SetValue(3);
	
	InsertComponent(list, 1, { a });
	InsertComponent(list, 2, { b });
	InsertComponent(list, 3, { c });

	LOG_SCOPE(__FUNCTION__);
	LOG_INFO("ARGUMENT COUNT : %d", argc);
	LOG_INFO("PROGRAM NAME   : %s", argv[0]);

	for (std::map<unsigned int, Component>::iterator _iter = list.begin();
		_iter != list.end(); _iter++) {
		LOG_INFO("ID : %d  VALUE : %d", _iter->first, _iter->second.AInstance.GetValue());
	}

	std::unique_ptr<Application> pApplication{ std::make_unique<Application>() };
	if (nullptr != pApplication) {
		if (pApplication->Initialize())
			nReturn = pApplication->Run();
	}
	else { LOG_FATAL("FAILED TO CREATE APPLICATION OBJECT"); }

	return nReturn;
}