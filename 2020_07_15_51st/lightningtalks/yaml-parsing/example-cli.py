#!/usr/bin/env python3

""" YAML one value editor CLI example
    author: Billy Duong

    Feel free to use/modify/edit this code.
"""

import sys, subprocess, uuid, argparse
from ruamel.yaml import YAML


# constants
ACTION_READ = 'READ'
ACTION_DELETE = 'DELETE'
ACTION_UPDATE = 'UPDATE'
ACTION_CHOICES = [ACTION_READ, ACTION_UPDATE, ACTION_DELETE]


# setup argument parser
parser = argparse.ArgumentParser(description='edit values of a yaml file')

parser.add_argument('action', choices=ACTION_CHOICES, help='action executed (READ = output value | UPDATE = update value | DELETE = delete key)')
parser.add_argument('target_file', help='target file')
parser.add_argument('key', help='key')

parser.add_argument('-nv', '--new-value', help='new value')
parser.add_argument('-iw', '--inplace-write', action='store_true', help='writes directly to the file (default is stdout)')
parser.add_argument('-v', '--verbose', action='store_true', help='additional information')


def patch(yamlobj):
    '''patch yaml object functionality'''

    def get_key(key):
        data = yamlobj
        for v in key.split('.'):
            data = data[v]
        return data

    def write_key(key, data):
        target = yamlobj
        for v in key.split('.')[:-1]:
            target = target[v]
        lastkey = key.split('.')[-1]
        target[lastkey] = data

    def delete_key(key):
        target = yamlobj
        for v in key.split('.')[:-1]:
            target = target[v]
        lastkey = key.split('.')[-1]
        del target[lastkey]

    yamlobj.get_key = get_key
    yamlobj.write_key = write_key
    yamlobj.delete_key = delete_key


if __name__ == '__main__':
    # parse arguments
    args = parser.parse_args()
    filepath = args.target_file
    key = args.key
    value = args.new_value
    action = args.action
    inplace_write = args.inplace_write
    VERBOSE = args.verbose

    # parse
    yaml = YAML() # uses roundtrip parser (keeps comments and order)
    result = yaml.load(open(filepath))
    patch(result) # add functions to object

    # action update/delete/read
    if action == ACTION_UPDATE:
        if VERBOSE:
            print(f'INFO: Modifying {key} in {filepath}, setting "{value}"\n')
        result.write_key(key, value)
    elif action == ACTION_DELETE:
        if VERBOSE:
            print(f'INFO: Deleting {key} from {filepath}\n')
        result.delete_key(key)
    elif action == ACTION_READ:
        if VERBOSE:
            print(f'INFO: Reading {key} from {filepath}')
        print(result.get_key(key))
        sys.exit(0)

    # output
    if inplace_write:
        yaml.dump(result, open(filepath, 'w'))
    else:
        print('OUTPUT:')
        yaml.dump(result, sys.stdout)