/* $Id$
 * (L)
*/
#ifndef OTCLASM_TOKENSX_HXX
#define OTCLASM_TOKENSX_HXX 1

#include <otclasm/tokens.hxx>
#include <otclasm/diag.hxx>

namespace otclasm { namespace {


regidx_t nextRegIdx(line_stream_t &stream) {
	token_t tok;
	nextToken(stream, tok);
	if (tok.empty()) {
		error("InvalidRegIdx", "Expected register index but got empty token");
		return INVALID_REGIDX;
	}
	const char *begin = tok.c_str();
	const char *end = begin + tok.size(); // Note that there's a '\0' in *end.
	const char *it = begin;
	char c;
	if (*it == '%') {
		++it;
		if (it == end) {
			error("InvalidRegIdx", "Register index ended unexpectedly");
			return INVALID_REGIDX;
		}
		if ((*it == '-') && ((it + 1) == end)) { // Don't care
			return 0;
		}
	}
	c = std::tolower(*it);
	if ((c == 'a') || (c == 'd')) {
		++it;
		if (it == end) {
			error("InvalidRegIdx", "Register index ended unexpectedly");
			return INVALID_REGIDX;
		}
	}

	//TODO avoid copying...
	token_t localCopy;
	if (it != begin) {
		localCopy = tok.substr(begin - it);
	}
	token_t const &inttok = (it == begin)? tok : localCopy;

	int radix = getIntRadix(inttok);
	if (radix < 0) {
		error("InvalidRegIdx", "Register index doesn't end on an integer");
		return INVALID_REGIDX;
	}

	uint64_t intval = getInt(inttok, radix);
	if (intval > 15) {
		error("InvalidRegIdx", "Register index is above 15");
		return INVALID_REGIDX;
	}

	return (regidx_t) intval;
}

uint8_t nextUInt8(line_stream_t &stream) {
	token_t tok;
	nextToken(stream, tok);

	int radix = getIntRadix(tok);
	if (radix < 0) {
		error("InvalidConst", "Token is not an integer");
		return 0;
	}

	uint64_t intval = getInt(tok, radix);
	if (intval >= 0x100) {
		error("ConstOutOfBounds", "Constant read as eight bit contant exceeds 0x100");
	}

	return (uint8_t)intval;
}

imm_t nextImm(symbol_table_in sym, line_stream_t &stream) {
	token_t tok;
	nextToken(stream, tok);
	imm_t res;

	res.type_bits = 0;
	res.value_bits = 0;

	if (tok.empty()) {
		error("InvalidImm", "Expected immediate but got empty token");
	}

	int radix = getIntRadix(tok);
	if (radix > 0) {
		uint64_t intval = getInt(tok, radix);
		if (intval > imm_t::IMM_MAXVAL) {
			error("ImmOutOfBounds", "Immediate exceeds maximum value");
		}
		res.type(imm_t::IMM);
		res.value((uint32_t)intval);
		return res;
	}

	// TODO operations and symboltable lookup.
}



}}

#endif /* _HXX */

