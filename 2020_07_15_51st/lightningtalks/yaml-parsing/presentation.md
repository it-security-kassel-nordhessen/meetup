# Automating YAML parsing / editing
whoami: Billy Duong


## Why?
Why automate?

- YAML is not machine parser friendly (e.g. regex)
- I needed to manage multiple files 'semi-regularly'
- Ex. ansible vault file, docker files, kubernetes, ...


## What?
What do I need?

- Required: Read, edit, delete values
- Required: Keep file structure!!
- Required: Keep comments in file!!
- Required: Additional scripting
- Optional: Edit values based on keys (my.long.key)


## How?
How did I solve it?

- Python 3 (personal preference)
- ruamel.yaml (based on PyYAML)


## Sources
More information:
- https://yaml.readthedocs.io/en/latest/
- https://yaml.org/
- https://en.wikipedia.org/wiki/YAML

YAML usage examples:
- https://docs.ansible.com/ansible/latest/user_guide/vault.html
- https://docs.docker.com/compose/
