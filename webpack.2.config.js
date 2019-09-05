const path = require("path");
const webpack = require("webpack");
const isProd = process.env.NODE_ENV === "production";
const mode = isProd ? "production" : "development";

const outputDir = path.join(__dirname, "build");

const HtmlWebpackPlugin = require("html-webpack-plugin")
const BundleAnalyzerPlugin = require("webpack-bundle-analyzer").BundleAnalyzerPlugin;

module.exports = {
  mode,
   target: "web",
  entry: "./test/BundleTest.bs.js",
  output: {
    path: outputDir,
    filename: "bundle.js"
  },
  plugins: [
     new BundleAnalyzerPlugin(),
      new webpack.IgnorePlugin(/^\.\/locale$/, /moment$/),
    new HtmlWebpackPlugin({
                inject: true,
                filename: "bundle.html",
                template: "test/index.html"
            })
  ],
  devtool: "none",
  resolve: {
    alias: {
    "@ant-design/icons/lib/dist$": path.join(__dirname, "test", "icons.js")
    }
  }
};