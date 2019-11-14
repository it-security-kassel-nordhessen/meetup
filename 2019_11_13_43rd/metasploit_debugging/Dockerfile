FROM ruby:latest
RUN apt-get update && apt-get install -y git autoconf build-essential libpcap-dev libpq-dev zlib1g-dev libsqlite3-dev vim openssh-server net-tools lsof netcat-openbsd
RUN useradd -ms /bin/bash msf
RUN gem install bundler pry rake
COPY pryrc/.pryrc /root/.pryrc 
COPY metasploit_gem_file/Gemfile /home/msf/Gemfile
WORKDIR /home/msf
