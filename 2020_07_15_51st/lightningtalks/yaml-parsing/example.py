#!/usr/bin/env python3
import sys
from ruamel.yaml import YAML

# for more see: https://yaml.readthedocs.io/en/latest/
 
# read
yaml = YAML() # uses roundtrip (keeps comments and order)
# yaml = YAML(typ='safe') # alternative, does not keep comments and order
result = yaml.load(open('[path_to_your_file]'))
 
# modify
print(result['db']['password']) # read value
result['db']['password'] = 'MY_NEW_SECRET' # create/update value
del result['deprecated']['key'] # delete key
 
# output
yaml.dump(result, sys.stdout) # write to stdout
yaml.dump(result, open('[path_to_your_file]', 'w')) # write to file inplace