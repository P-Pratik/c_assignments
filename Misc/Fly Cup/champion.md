# Task 1
```
gsutil cp gs://spls/gsp397/examples/* .

AUTOML_PROXY=$(gcloud run services describe automl-proxy --platform managed --region  --format 'value(status.url)')

curl -X POST -H "Content-Type: application/json" $AUTOML_PROXY/v1 -d "@${INPUT_DATA_FILE}" | jq
```

# Task 2

```
SELECT distinct(events_name), (event_id) AS event_info FROM `.drl.pilot-event-times` ORDER BY event_info LIMIT 100
```

```
INPUT_DATA_FILE=MANHATTAN-JSON

AUTOML_PROXY=$(gcloud run services describe automl-proxy --platform managed --region  --format 'value(status.url)')

curl -X POST -H "Content-Type: application/json" $AUTOML_PROXY/v1 -d "@${INPUT_DATA_FILE}" | jq
```

# Task 3 


```
SELECT distinct(events_name), pilot_id, rounds_id, (rank) AS event_rank FROM `.drl.pilot-event-times` WHERE events_name = 'Ohio Crash Site' and rounds_id=40 ORDER BY event_rank LIMIT 100
```

```
INPUT_DATA_FILE=OHIO-JSON

AUTOML_PROXY=$(gcloud run services describe automl-proxy --platform managed --region  --format 'value(status.url)')

curl -X POST -H "Content-Type: application/json" $AUTOML_PROXY/v1 -d "@${INPUT_DATA_FILE}" | jq
```

# Task 4


```
SELECT distinct(events_name), pilot_id, (minimum_time) AS event_time FROM `.drl.pilot-event-times` WHERE events_name = 'Miami Nights' ORDER BY event_time LIMIT 100
```

```
INPUT_DATA_FILE=MIAMI-JSON

AUTOML_PROXY=$(gcloud run services describe automl-proxy --platform managed --region  --format 'value(status.url)')

curl -X POST -H "Content-Type: application/json" $AUTOML_PROXY/v1 -d "@${INPUT_DATA_FILE}" | jq
```
# Task 5 and 6 

```
gsutil cp gs://spls/gsp397/drl-web/webapp.zip .

unzip webapp.zip

gcloud auth configure-docker us-docker.pkg.dev

docker build . -t us-docker.pkg.dev/$DEVSHELL_PROJECT_ID/drl-lap-time-predictor/webapp:0.0.1

gcloud artifacts repositories create drl-lap-time-predictor --repository-format=docker --location=us

docker push us-docker.pkg.dev/$DEVSHELL_PROJECT_ID/drl-lap-time-predictor/webapp:0.0.1

```
