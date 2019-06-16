/* $Id$
 * (L)
*/
#ifndef OTCLASML_INFILE_HXX
#define OTCLASML_INFILE_HXX 1

#include <istream>
#include <sstream>

#include <boost/iostreams/device/mapped_file.hpp>
// #include <boost/interprocess/managed_shared_memory.hpp>

#include <otclasml/StringView.hxx>

namespace otclasml { namespace io { namespace {

class InFileMemMng {
public:
	virtual ~InFileMemMng() {}
};

class InFile {
private:
	StringView      mStr;
	InFileMemMng    *mMem;

public:
	InFile() : mStr(nullptr, 0), mMem(nullptr) {}
	InFile(InFile &&r) : mStr(r.mStr), mMem(r.mMem) {
		r.mMem = nullptr;
	}
	~InFile() { destroy(); }

private:
	void destroy() {
		if (mMem != nullptr) {
			delete mMem;
			mMem = nullptr;
		}
	}

private:
	struct MemMngViaMmap : InFileMemMng {
		boost::iostreams::mapped_file_source mMmf;	
	};
	struct MemMngViaString : InFileMemMng {
		std::string mStr;
	};

public:
	// Create a memory mapped file source.
	void openFile(std::string const &path) {
		destroy();

		MemMngViaMmap &mm = *(new MemMngViaMmap());
		mm.mMmf.open(path);

		mStr = StringView(mm.mMmf.data(), mm.mMmf.size());
	}

public:
	// Read a whole stream to memory, see also
	// https://stackoverflow.com/questions/116038/what-is-the-best-way-to-read-an-entire-file-into-a-stdstring-in-c
	void openCharStream(std::istream &in) {
		destroy();

		MemMngViaString &mm = *(new MemMngViaString());
		std::stringstream sstr;
		sstr << in.rdbuf();
		mm.mStr = sstr.str();

		mStr = StringView(mm.mStr.data(), mm.mStr.size());
	}

public:
	StringView strv() const {
		return mStr;
	}
};

} } }

#endif /* _HXX */

