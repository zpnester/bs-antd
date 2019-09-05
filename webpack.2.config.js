const path = require("path");
const isProd = process.env.NODE_ENV === "production";
const mode = isProd ? "production" : "development";

const outputDir = path.join(__dirname, "build");

const HtmlWebpackPlugin = require("html-webpack-plugin")

module.exports = {
  mode,
   target: "web",
  entry: "./test/BundleTest.bs.js",
  output: {
    path: outputDir,
    filename: "bundle.js"
  },
  plugins: [
    new HtmlWebpackPlugin({
                inject: true,
                filename: "bundle.html",
                template: "test/index.html"
            })
  ],
  devtool: "none"
};