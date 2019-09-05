const path = require("path");
const outputDir = path.join(__dirname, "build");
const webpack = require("webpack");

const isProd = process.env.NODE_ENV === "production";
const mode = isProd ? "production" : "development";

const HtmlWebpackPlugin = require("html-webpack-plugin")
const CopyWebpackPlugin = require("copy-webpack-plugin")

module.exports = {
    entry: "./test/Test.bs.js",
    mode: "development",
       target: "web",
    output: {
        path: outputDir,
        filename: "test.js",
        publicPath: ""
    }, plugins: [
        new HtmlWebpackPlugin({
            inject: true,
            template: "test/index.html"
        }),
        new CopyWebpackPlugin([
            { from: "test_static", to: "" },
        ])
    ],
    module: {
        rules: [
            {
                test: /\.css$/,
                use: ["style-loader", "css-loader"],
            },
        ],
    },
    devServer: {
        contentBase: outputDir,
        port: 9000
    }
};
