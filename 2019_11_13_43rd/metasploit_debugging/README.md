# Instruction for an encapsulated docker metasploit environment
```
docker build . -t msf
docker run -ti -v `pwd`/metasploit-framework:/home/msf msf bash
```
or

```
docker run -ti -v `pwd`/metasploit-framework:/home/msf --network=<NETWORK> msf bash
``` 
to add it to a specific network (use docker network list to get a list of all networks)

`bundle install`

Added gem 'pry-byebug', 'pry-doc'
Debug Viewing (pry), Debug Stepping (pry-byebug), Debug with Documentation (pry-doc)

Alternative way to add container to a network:
after start of metasploit container:
`docker network connect <network_name> <container_name>` 
`docker network disconnect` 
respectively
