/*
    Moving average CHUNK
	Dimitrisv22@gmail.com 
	Git : https://github.com/DimitrisVlachos
*/
#ifndef _moving_average_chunk_hpp_
#define _moving_average_chunk_hpp_
#include <stdint.h>

template <typename base_t>
class moving_average_chunk_c {
	private:
	base_t ratio;
	base_t scalar_a;
	base_t scalar_b;
	base_t* m_average;
	size_t element_count;

	public:
	moving_average_chunk_c() : m_average(nullptr) {  }
	~moving_average_chunk_c() { delete[] m_average; }

	inline bool init(const size_t ielement_count,const size_t update_cycles,const base_t sratio = (base_t)1) {
		element_count = ielement_count;
		ratio = sratio;
		scalar_a = ratio / update_cycles;
		scalar_b = ratio - scalar_a;
		delete[] m_average;
		m_average = new base_t[element_count];
        return m_average != nullptr;
	}

	inline void reset(const base_t initial,const size_t index) {
		m_average[index] = initial;
	}

	inline const base_t update(const base_t sample,const size_t index) {
		return (m_average[index] = (sample * scalar_a) + (m_average[index] * scalar_b));
	}

	inline const double get(const size_t i) const {
		return m_average[i];
	}

	inline const double* get_chunk() const {
		return m_average;
	}

	inline const double* get_chunk(const size_t index) const {
		return &m_average[index];
	}
};

#endif

