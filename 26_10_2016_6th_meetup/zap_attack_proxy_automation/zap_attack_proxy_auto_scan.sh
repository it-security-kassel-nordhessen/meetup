#!/bin/bash

#./zap.sh -config api.key=hfu82d92ijf -daemon

scanUrl='http://192.168.15.8/bWAPP/'
zapHost='127.0.0.1:8080'
apiKey='hfu82d92ijf'

###########################################
#step 1
###########################################


contextJson=$(curl -s "http://${zapHost}/JSON/context/action/importContext/?zapapiformat=JSON&apikey=${apiKey}&contextFile=%2Fhome%2Fmouse%2F.ZAP%2Fcontexts%2FbWAPP_kontext.context")
contextId=$(echo "$contextJson" | awk -F'contextId":"' '{print $2}' | cut -d'"' -f1)

userListJson=$(curl -s "${zapHost}/JSON/users/view/usersList/?zapapiformat=JSON&contextId=${contextId}")
userId=$(echo "$userListJson" | awk -F'"id":"' '{print $2}' | cut -d'"' -f1)

echo "step 1 userId: $userId context id: $contextId"


###########################################
#step 2
###########################################

spiderScanJson=$(curl -s "${zapHost}/JSON/spider/action/scan/?zapapiformat=JSON&apikey=${apiKey}&url=${scanUrl}&maxChildren=0&recurse=true&contextName=bWAPP_kontext&subtreeOnly=")
spiderScanId=$(echo "$spiderScanJson" | awk -F'"scan":"' '{print $2}' | cut -d'"' -f1)

statusSpiderScan=0

while [  $statusSpiderScan -lt 99 ]; do
	statusSpiderScanJson=$(curl -s "${zapHost}/JSON/spider/view/status/?zapapiformat=JSON&scanId=${spiderScanId}")
	statusSpiderScan=$(echo "$statusSpiderScanJson" | awk -F'"status":"' '{print $2}' | cut -d'"' -f1)
	echo "spider progress: ${statusSpiderScan}"
	sleep 0.1
done

echo "step 2 spider scan id: $spiderScanId"


###########################################
#step 3
###########################################

ascanJson=$(curl -s "${zapHost}/JSON/ascan/action/scanAsUser/?zapapiformat=JSON&apikey=${apiKey}&url=${scanUrl}&contextId=${contextId}&userId=${userId}&recurse=true&scanPolicyName=&method=&postData=")
aScanId=$(echo "$ascanJson" | awk -F'"scan":"' '{print $2}' | cut -d'"' -f1)

statusAScan=0

while [  $statusAScan -lt 99 ]; do
	
	statusAScanJson=$(curl -s "${zapHost}/JSON/ascan/view/scans/?zapapiformat=JSON" | tr ',' '\n' | tail -n 3)

	statusAScan=$(echo "$statusAScanJson" | awk -F'"progress":"' '{print $2}' | cut -d'"' -f1)

	echo "ascan progress: ${statusAScan}"
	sleep 2
done

echo "step 3 ascan id: $aScanId"


###########################################
#step 4
###########################################

curl -s "${zapHost}/OTHER/core/other/htmlreport/?apikey=${apiKey}" > /home/mouse/projects/meetup_talk_26_10_2016/share/report.html

echo 'step 4 report file: /home/mouse/projects/meetup_talk_26_10_2016/share/report.html'

sleep 2

firefox "${zapHost}/OTHER/core/other/htmlreport/?apikey=${apiKey}"

