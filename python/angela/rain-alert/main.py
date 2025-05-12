import requests
from twilio.rest import Client

account_sid = <ACCOUNT_SID>
auth_token = <AUTH_TOKEN>
API_KEY = <AUTH_KEY>
LAT = 30.73
LON = 76.77
LAT1 = 53.45
LON1 = 33.29

parameters = {
    "lat": LAT,
    "lon": LON,
    "appid": API_KEY,
}
response = requests.get("https://api.openweathermap.org/data/2.5/weather", parameters).json()
weather_data = response['weather'][0]['main']

if weather_data == 'Rain':
    client = Client(account_sid, auth_token)

    message = client.messages.create(
    from_='+14132484122',
    body='Bring an umbrella ☂️',
    to='+918146806068'
    )

    print(message.sid)


