#pragma once
#include <iostream>

namespace ofc {
	struct OutputCF {
		std::ostream& ofs1;
		std::ostream& os2;
		std::istream& is;
		OutputCF(std::ofstream& o,std::ostream& o1,std::istream& i)
			:ofs1(o),os2(o1),is(i){}
	};
	template <class Data>
	inline OutputCF& operator<<(OutputCF& ocf, Data s) {
		ocf.ofs1 << s;
		ocf.os2 << s;
		return ocf;
	}
	template <class Data>
	inline OutputCF& operator>>(OutputCF& ocf, Data& s) {
		ocf.is >> s;
		ocf.ofs1 << s;
		return ocf;
	}

}
