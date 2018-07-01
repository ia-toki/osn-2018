# berebut-pizza code name

## Where to look

1. Testcase: `src/testcases`
2. Translation: `src/i18n.js`
3. Helps: `src/helps`

## How to try

1. Make sure install `node`
2. Make sure install `yarn`
3. `yarn install`
4. `yarn serve`
5. open the webpage, should be at `localhost:8080`

## How to build

1. Change `baseUrl` in `vue.config.js` (if you will access it from `http://www.example.com/`, `baseUrl` is `/`, but if it's like this `http://www.example.com/test`, `baseUrl` is `/test/`)
2. `yarn build`
3. If it gives an error, ignore it, terminate `Ctrl+C`, and do it again `yarn build`
4. If it fails... It means there's really a bug (TODO), but if it's success:
5. There's `dist` folder... just put it in the server
