#ifndef TCLASM_ZTSTRING_HXX
#define TCLASM_ZTSTRING_HXX

#include <cstring>

namespace tclasm {

	struct ztstring {
		const char *data;

		explicit ztstring(const char *data_) : data(data_) {}
		ztstring(const ztstring &r) : data(r.data) {}

		int cmp(const ztstring r) const {
			return std::strcmp(data, r.data);
		}
		bool less(const ztstring r) const {
			return cmp(r) < 0;
		}
	};

	bool operator< (const ztstring a, const ztstring b) {
		return a.less(b);
	}

	/* extern const ztstring *findSorted(const ztstring *begin, const ztstring *end, const ztstring val); */
}

#endif /* _HXX */

