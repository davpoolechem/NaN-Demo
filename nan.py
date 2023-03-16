import re
import subprocess
import sys

if __name__ == "__main__":
  #== sanity checks ==#
  assert len(sys.argv) == 4
  
  for arg in sys.argv[1:]:
    assert re.search("[0-9]", arg) is not None

  #== compile NaN demo ==#
  subprocess.run([ "g++", "nan.cpp", "-o", "nan" ])
  
  #== execute NaN demo ==#
  subprocess.run([ "./nan", *sys.argv[1:] ])
