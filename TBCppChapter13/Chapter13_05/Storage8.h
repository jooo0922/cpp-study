#pragma once

// 클래스 템플릿 선언
template <class T>

// template initialization 로 지정된 타입의 요소를 8개까지 저장할 수 있는 클래스
class Storage8
{
private:
	T m_array[8];

public:
	void set(int index, const T& value)
	{
		m_array[index] = value;
	}

	const T& get(int index)
	{
		return m_array[index];
	}
};