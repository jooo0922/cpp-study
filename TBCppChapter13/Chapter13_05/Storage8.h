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

/*
	bool 타입 요소는 1 bit 로 저장 가능한데,
	기존 Storage8 클래스는 정적 배열을 멤버변수로 사용하기 때문에,
	bool 타입에 한해서는 메모리 낭비가 발생하는 이슈가 있음.

	이를 해결하기 위해,
	bool 타입의 요소에 대해서는 템플릿 특수화를 선언함으로써,

	1 byte (== 8 bits)의 메모리만 할당해놓고,
	비트마스크 연산을 활용해서 getter 와 setter 를 구현함으로써,
	8 bits 메모리에 8개 까지의 bool 타입 요소를 저장할 수 있도록 
	
	template specialization 을 선언한 것!
*/
template<>
class Storage8<bool>
{
private:
	unsigned char m_data; // 1 byte(== 8 bits) 크기에 해당하는 unsigned char 타입의 멤버변수 선언
	
public:
	// 생성자 함수 
	// 멤버 초기화 리스트를 통해 8 bits 메모리를 모두 0으로 초기화
	Storage8() : m_data(0) 
	{}

	void set(int index, bool value)
	{
		/*
			매개변수로 전달받는 index 개수만큼
			left shift(<<) 이동하여, 비트마스킹에 사용할 8 bits 데이터를 계산함.

			ex> index 를 2로 입력받으면,
			0000 0001 을 2번 left shift 하여
			0000 0100 으로 만듦.
		*/
		unsigned char mask = 1 << index;

		// bool 타입 입력값에 따른 bit masking 수행
		if (value)
		{
			// bool 타입 요소를 true 로 입력받았을 경우, 
			// m_data 와 mask 에 있는 비트값 중 하나라도 1이면 m_data 의 비트값을 1로 덮어씀.
			// -> m_data 의 비트값과 관계없이 mask 의 비트값이 1인 지점이 1로 덮어쓰임.
			m_data |= mask;
		}
		else
		{
			// bool 타입 요소를 false 로 입력받았을 경우, 
			// m_data 와 mask 에 있는 비트값이 모두 1이어야 m_data 의 비트값을 1로 덮어씀.
			// -> m_data 의 비트값과 관계없이 mask 의 비트값만 0 이여도 0으로 덮어쓰임.
			// 이때, mask 의 비트값에 대해 보수를 취한 후, bit masking 연산 수행
			// ex> mask 가 0000 0001 이라면, ~mask 는 1111 1110 로 뒤집어 짐.
			m_data &= ~mask;
		}
	}

	bool get(int index)
	{
		// bitwise and 연산에 사용할 비트값을 left shift 로 구현
		unsigned char mask = 1 << index;

		/*
		* m_data 와 mask 의 각 자릿수 비트값이 모두 1이면 1, 아니면 0 으로 나오도록
		* bitwise and 연산을 통해 새로운 비트값을 만들어내고,
		* 
		* 그 비트값이 0000 0000 과 다르면 1을 반환하고,
		* 같으면 0을 반환하는 조건문을 수행함.
		* 
		* 이는 어떤 결과를 유도한 것이냐면,
		* mask 가 1인 자릿수의 m_data 의 비트값이 0이면 0을 반환하게 되고,
		* mask 가 1인 자릿수의 m_data 의 비트값이 1이면 1을 반환하게 되는
		* 결과를 유도한 것임!
		* 
		* 이렇게 함으로써, m_data 에 저장된 비트값을
		* 읽을 수 있는 getter 함수를 만든 것!
		*/
		return (m_data & mask) != 0;
	}
};