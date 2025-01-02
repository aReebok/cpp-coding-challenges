#!/usr/bin/env

curl "https://generativelanguage.googleapis.com/v1beta/models/gemini-1.5-flash:generateContent?key=$GEMINI_API_KEY" \
-H 'Content-Type: application/json' \
-X POST \
-d '{
  "contents": [{
    "parts":[{"text": "What are some of the most fun and challenging C++ projects?"}]
    }]
   }'

echo "End of Response"