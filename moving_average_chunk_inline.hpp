/*
    Moving average CHUNK INLINE
	Dimitrisv22@gmail.com 
	Git : https://github.com/DimitrisVlachos
*/
#ifndef _moving_average_chunk_inline_hpp_
#define _moving_average_chunk_inline_hpp_
#include <stdint.h>

template <typename base_t,const size_t element_count,const size_t update_cycles>
class moving_average_chunk_inline_c {
	private:
	static constexpr base_t ratio = (base_t)1;
	static constexpr base_t scalar_a = ratio / update_cycles;
	static constexpr base_t scalar_b = ratio - scalar_a;
	base_t* m_average;

	public:
	moving_average_chunk_inline_c()  { m_average = new base_t[element_count]; }
	~moving_average_chunk_inline_c() { delete[] m_average; }

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

