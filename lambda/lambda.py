import json
import boto3

def lambda_handler(event, context):
    # print(event['body'])
    s3 = boto3.resource('s3')
    bucketName = 'dnblak-cloudfront-us-west-2'
    bucket = s3.Bucket(bucketName)

    bodyEncoded = event['isBase64Encoded']
    if bodyEncoded:
        body = base64.b64decode(event['body']).decode('utf8')
    else:
        body = event['body']

    path = 'storyline/buttonGame/data.json'
    rawData = json.loads(body)
    # print(rawData)
    data = json.dumps(rawData).encode('utf-8')
    # print(data)
    bucket.put_object(
        ContentType='application/json',
        Key=path,
        Body=data,
    )
    return {
        'statusCode': 200,
        'body': json.dumps('data written to S3')
    }
