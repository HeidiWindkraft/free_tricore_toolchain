#!/usr/bin/env python3

import sys;
import yaml;

def read_insn_array_from_yaml(stream):
  return yaml.safe_load(stream);

def print_table(insn_array):
  for insn in insn_array["insns"]:
    print ( insn["mnem"] + "\t" + insn["format"] + "\t" + insn["op2"] + "\t" + insn["op1"] + "\t" + insn["op2"]
      + "\t" + insn["misc1"] + "\t" + insn["misc2"] + "\t\t\t" + insn['target']);

def print_yaml(insn_array):
  print (yaml.dump(insn_array));

def gen_mnem(insn_array, h_dir, c_dir):
  mnems = set();
  for insn in insn_array["insns"]:
    mnems.add(insn["mnem"]);
  smnems = sorted(mnems);
  gen_mnem_enum_h(smnems, h_dir, c_dir);
  gen_mnem_str(smnems, h_dir, c_dir);

def gen_mnem_enum_h(smnems, h_dir, c_dir):
  e = [];
  e.append("""
/* ftct/mnemonics_enum.hxx
 *
 * This file contains the mnemonics of the target hardware.
 * This file is generated.
 *
 * License: GNU GPL 3, see LICENSE file.
*/
#ifndef FTCT_MNEMONICS_ENUM_HXX
#define FTCT_MNEMONICS_ENUM_HXX 1

namespace ftct {

namespace mnemonics {

enum mnemonic_index_e : unsigned int {
""");
  last_index = 0;
  max_strlen = 0;
  for index, mnem in enumerate(smnems):
    ident = mnem.upper().replace('.','_');
    e.append("  " + ident + " = " + str(index) + "u,");
    len_ident = len(ident);
    if (len_ident > max_strlen):
      max_strlen = len_ident;
    last_index = index;
  e.append("  MNEMONICS_INDEX_SIZE = " + str(last_index + 1) + "u");
  e.append("""
}; // End of enum mnemonic_index_e.

} // End of namespace mnemonics.

namespace mnemonic_str_props {
  enum mnemonic_str_props_e : unsigned int {
    MNEMONICS_STR_MAX_SIZE = """+str(max_strlen)+"""u
  };
}

} // End of namespace ftct.

#endif

""");
  e_str = "\n".join(e);
  with open(h_dir +"/mnemonics_enum.hxx", "w") as hf:
    print(e_str, file=hf);
  return;

def gen_mnem_str(smnems, h_dir, c_dir):
  c = [];
  c.append("""
/* mnemonics_str.cxx
 *
 * This file contains the mnemonic strings of the target hardware.
 * This file is generated.
 *
 * License: GNU GPL 3, see LICENSE file.
*/
#include "ftct/private/mnemonics_impl.hxx"

namespace ftct {

using namespace mnemonic_str_props;

// TODO see _outdated.
// TODO just use an array of `const char *`. This way the array element size is a power of two and the algorithms can be more generic.
const char mnemonic_strings_by_index[MNEMONICS_INDEX_SIZE + 1][MNEMONICS_STR_MAX_SIZE + 1] = {
""");
  last_index = 0;
  max_strlen = 0;
  for index, mnem in enumerate(smnems):
    ident = mnem.lower();
    c.append('  "' + ident + '", // = [' + str(index) + ']');
  c.append('  "~~"');
  c.append("""
}; // End of mnemonic_strings_by_index.

} // End of namespace ftct.
""");
  c_str = "\n".join(c);
  with open(c_dir +"/mnemonics_str.cxx", "w") as f:
    print(c_str, file=f);
  return;


def main():
  insn_array = read_insn_array_from_yaml(sys.stdin);
  if sys.argv[1] == "print_table":
    print_table(insn_array);
  if sys.argv[1] == "print_yaml":
    print_yaml(insn_array);
  if sys.argv[1] == "gen":
    h_dir = sys.argv[2];
    c_dir = sys.argv[3];
    gen_mnem(insn_array, h_dir, c_dir);




if __name__ == '__main__':
  main()
