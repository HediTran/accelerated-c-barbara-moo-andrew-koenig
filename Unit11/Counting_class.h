#pragma once

template<typename T>
class Counter {
public:
	Counter() { ++Obj_created; }
	Counter(const Counter&) { ++Obj_created; }

	static size_t howManyCreated() { return Obj_created; }
private:
	static size_t Obj_created;
};

template<typename T>
size_t Counter<T>::Obj_created = 0;