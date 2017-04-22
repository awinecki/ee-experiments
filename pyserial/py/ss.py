import requests


r = requests.post(
    'https://insights-collector.newrelic.com/v1/accounts/1335285/events',
    headers={
        'X-Insert-Key': 'wgeNjZlQDaBPsU35eEr_AQTmu3jZTm4K'
    }, json={
        'eventType': "Tour:Creation",
        'userId': 1,
    }
)
