#!/bin/bash
docker build -t vuln-spring-boot .
docker stop vuln-spring-boot
docker rm vuln-spring-boot
docker run -d -p 127.0.0.1:8080:8080 --name vuln-spring-boot vuln-spring-boot
